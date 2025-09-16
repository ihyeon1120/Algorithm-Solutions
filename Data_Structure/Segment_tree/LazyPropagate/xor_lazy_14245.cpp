// Problem: BOJ 14245

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct LazyPropagation {
    vector<ll> arr;
    vector<ll> tree;
    vector<ll> lazy;
    int dValue;
    int sz;

    ll merge(ll a, ll b) { return a+b; }

    void init(int node, int s, int e) {
        if (s == e) tree[node] = arr[s];
        else {
            int m = (s + e) / 2;
            init(2*node, s, m);
            init(2*node + 1, m + 1, e);
            tree[node] = merge(tree[2*node], tree[2*node + 1]);
        }
    }

    LazyPropagation(const vector<ll>& a) {
        arr = a;
        sz = arr.size();
        dValue = 0;
        int h = (int)ceil(log2(sz));
        int tree_sz = (1 << (h + 1));
        tree = vector<ll>(tree_sz);
        lazy = vector<ll>(tree_sz);
        init(1, 0, sz-1);
    }

    void propagate(int node, int s, int e){
        if (lazy[node] != 0) {
            tree[node] = tree[node] ^ lazy[node];
            if (s != e) {
                lazy[2*node] ^= lazy[node];
                lazy[2*node + 1] ^= lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int s, int e, int l ,int r, int val) {
        propagate(node, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            tree[node] = tree[node] ^ val;
            if (s != e) {
                lazy[2*node] ^= val;
                lazy[2*node + 1] ^= val; 
            }
            return;
        }
        int m = (s + e) / 2;
        update(2*node, s, m, l, r, val);
        update(2*node+1, m+1, e, l, r, val);
        tree[node] = merge(tree[2*node], tree[2*node + 1]);
    }

    ll query(int node, int s, int e, int l, int r) {
        propagate(node, s, e);
        if (r < s || e < l) return dValue;
        if (l <= s && e <= r) return tree[node];
        int m = (s+e) / 2;
        return merge(query(2*node, s, m, l, r), query(2*node+1, m+1, e, l, r));
    }

    void update(int l, int r, ll val) { update(1, 0, sz-1, l, r, val); }
    ll query(int l, int r) { return query(1, 0, sz-1, l, r); }

};

void solve() {
    int N; cin >> N;
    vector<ll> arr(N); for (int i = 0; i < N; i++) cin >> arr[i];
    LazyPropagation seg{arr};
    int M; cin >> M;
    while (M--)
    {
        int t; cin >> t;
        if (t == 1) {
            int a, b, c; cin >> a >> b >> c;
            seg.update(a, b, c);
        }
        else {
            int idx; cin >> idx;
            cout << seg.query(idx, idx) << endl;
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}