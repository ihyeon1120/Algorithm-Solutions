// Problem: BOJ 12844

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct lazy_prapagation {
    vector<ll> arr;
    vector<ll> tree;
    vector<ll> lazy;
    int sz;
    int dValue;

    ll merge(ll a, ll b) { return a ^ b; }

    void init(int node, int s, int e) {
        if (s == e) tree[node] = arr[s];
        else {
            int m = (s + e) / 2;
            init(2*node, s, m);
            init(2*node+1, m+1, e);
            tree[node] = merge(tree[2*node], tree[2*node+1]);
        }
    }

    lazy_prapagation(const vector<ll>& a) {
        arr = a;
        sz = sz(arr);
        int h = (int)ceil(log2(sz));
        int tree_sz = (1 << (h+1));
        tree = vector<ll>(tree_sz);
        lazy = vector<ll>(tree_sz);
        dValue = 0;
        init(1, 0, sz-1);
    }
    
    void propagate(int node, int s, int e) {
        if (lazy[node] != 0) {
            // a ^ a = 0, a ^ 0 = a 두 연산에 의해 홀짝으로 구분
            if ((e - s + 1) % 2 == 1){
                tree[node] ^= lazy[node];
            } 
            if (s != e) {
                lazy[2*node] ^= lazy[node];
                lazy[2*node+1] ^= lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int s, int e, int l, int r, int val) {
        propagate(node, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            if ((e - s + 1) % 2 == 1){
                tree[node] ^= val;
            } 
            if (s != e) {
                lazy[2*node] ^= val;
                lazy[2*node+1] ^= val;
            }
            return;
        }
        int m = (s + e) / 2;
        update(2*node, s, m, l, r, val);
        update(2*node+1, m+1, e, l, r, val);
        tree[node] = merge(tree[2*node],  tree[2*node+1]);
    }

    ll query(int node, int s, int e, int l, int r) {
        propagate(node, s, e);
        if (r < s || e < l) return dValue;
        if (l <= s && e <= r) return tree[node];
        int m = (s + e) / 2;
        return merge(query(2*node, s, m, l, r), query(2*node+1, m+1, e, l, r));
    }

    void update(int l, int r, int val) { update(1, 0, sz-1, l, r, val); }
    ll query(int l, int r) { return query(1, 0, sz-1, l, r); }

};

void solve() {
    int n; cin >> n;
    vector<ll> arr(n); for(int i = 0; i < n; i++) cin >> arr[i];
    lazy_prapagation seg{arr};
    int m; cin >> m;
    while(m--) {
        int t; cin >> t;
        if (t == 1) {
            int a, b, c; cin >> a >> b >> c;
            seg.update(a, b, c);
        } else {
            int a, b; cin >> a >> b;
            cout << seg.query(a, b) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}