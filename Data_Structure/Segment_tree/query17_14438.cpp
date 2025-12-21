// Problem: BOJ 14438

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct min_seg {

    vector<ll> tree;
    vector<ll> arr;
    int sz;
    ll dValue;

    ll merge(ll a, ll b) {
        return min(a, b);
    }

    void init(int node, int s, int e) {
        if (s == e) tree[node] = arr[s];
        else {
            int m = (s + e) / 2;
            init(2*node, s, m);
            init(2*node + 1, m + 1, e);
            tree[node] = merge(tree[2*node], tree[2*node + 1]);
        }
    }

    min_seg(const vector<ll> &a) {
        arr = a;
        sz = sz(a);
        int h = (int)ceil(log2(sz));
        int tree_sz = (1 << (h+1));
        tree = vector<ll>(tree_sz);
        dValue = LONG_LONG_MAX;
        init(1, 0, sz-1);
    }

    void update(int node, int s, int e, int idx, ll val) {
        if (idx < s || e < idx) return;
        if (s == e) {
            arr[s] = val;
            tree[node] = val;
            return;
        }
        int m = (s + e) / 2;
        update(2*node, s, m, idx, val);
        update(2*node + 1, m + 1, e, idx, val);
        tree[node] = merge(tree[2*node], tree[2*node+1]);

    }

    ll query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return dValue;
        if (l <= s && e <= r) return tree[node];
        int m = (s + e) / 2;
        return merge(query(2*node, s, m, l, r), query(2*node + 1, m + 1, e, l ,r));
    }

    void update(int idx, ll val) { update(1, 0, sz-1, idx, val); }
    ll query(int l, int r) { return query(1, 0, sz-1, l, r); }
};

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    min_seg ms{a};
    int m; cin >> m;
    while(m--) {
        int t; cin >> t;
        if (t == 1) {
            int idx; cin >> idx;
            ll val; cin >> val;
            ms.update(idx-1, val);
        }
        else {
            int l, r; cin >> l >> r;
            cout << ms.query(l-1, r-1) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}