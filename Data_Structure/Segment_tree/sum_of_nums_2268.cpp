// Problem: BOJ 2268

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct segment_tree {
    vector<ll> tree;
    vector<ll> arr;
    int sz;

    ll merge(ll a, ll b) { return a + b; }

    void init(int node, int s, int e) {
        if (s == e) tree[node] = arr[s];
        else {
            int m = (s + e) / 2;
            init(2*node, s, m);
            init(2*node+1, m+1, e);
            tree[node] = merge(tree[2*node], tree[2*node+1]);
        }
    } 

    segment_tree(const vector<ll> &a) {
        arr = a;
        sz = sz(a);
        int h = (int)ceil(log2(sz));
        int tree_sz = (1 << (h + 1));
        tree = vector<ll>(tree_sz);
        init(1, 0, sz-1);
    }

    void update(int node, int s, int e, int idx, ll x) {
        if (idx < s || e < idx) return;
        if (s == e) {
            arr[s] = x;
            tree[node] = arr[s];
            return;
        }
        int m = (s + e) / 2;
        update(2*node, s, m, idx, x);
        update(2*node + 1, m + 1, e, idx, x);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    ll query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[node];
        int m = (s + e) / 2;
        return merge(query(2*node, s, m, l, r), query(2*node + 1, m + 1, e, l, r));
    }

    void update(int idx, ll x) { update(1, 0, sz-1, idx, x); }
    ll query(int l, int r) {return query(1, 0, sz-1, l, r); }

};

void solve() {
    int n, m; cin >> n >> m;
    vector<ll> arr(n, 0);
    segment_tree seg{arr};
    while(m--) {
        int q, a, b; cin >> q >> a >> b;
        if (q == 0) {
            if (a > b) swap(a, b);
            cout << seg.query(a-1, b-1) << endl;
        }
        else seg.update(a-1, b);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}