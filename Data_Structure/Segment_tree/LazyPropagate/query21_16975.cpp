// Problem: BOJ 16975

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
    vector<ll> lazy;
    vector<ll> tree;
    int dValue;
    int sz;

    ll merge(ll a, ll b) { return a + b; }

    void init(int node, int start, int end) {
        if (start == end) tree[node] = arr[start];
        else {
            int mid = (start + end) / 2;
            init(2*node, start, mid);
            init(2*node + 1, mid + 1, end);
            tree[node] = merge(tree[2*node], tree[2*node + 1]);
        }
    }

    LazyPropagation(const vector<ll>& a) {
        arr = a;
        sz = sz(arr);
        int h = (int)ceil(log2(sz));
        int tree_sz = (1 << (h+1));
        tree = vector<ll>(tree_sz);
        lazy = vector<ll>(tree_sz, 0);
        dValue = 0;
        init(1, 0 , sz-1);
    }
    
    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            // s == e면 단말노드여서 아래로 전파하지 않음!
            if (start != end) {
                lazy[2*node] += lazy[node];
                lazy[2*node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update_range(int node, int s, int e, int l, int r, ll val) {
        propagate(node, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            tree[node] += (e - s + 1) * val;
            if (s != e) {
                lazy[2*node] += val;
                lazy[2*node + 1] += val;
            }
            return;
        }
        int mid = (s + e) / 2;
        update_range(2*node, s, mid, l, r, val);
        update_range(2*node + 1, mid + 1, e, l, r, val);
        tree[node] = merge(tree[2*node], tree[2*node + 1]);
    }

    ll query(int node, int s, int e, int l, int r) {
        propagate(node, s, e);
        if (r < s || e < l) return dValue;
        if (l <= s && e <= r) return tree[node];
        int m = (s+e)/2;
        return merge(query(2*node, s, m, l, r), query(2*node + 1, m+1, e, l, r));
    }

    void update_range(int l, int r, ll val) { update_range(1, 0, sz-1, l, r, val); }
    ll query(int l, int r) { return query(1, 0, sz-1, l, r); }

};

void solve() {
    int N; cin >> N;
    vector<ll> arr(N); for(int i=0; i<N; i++) cin >> arr[i];
    LazyPropagation seg{arr};
    int M; cin >> M;
    while (M--) {
        int type; cin >> type;
        if (type == 1){
            ll a, b, c; cin >> a >> b >> c;
            seg.update_range(a-1, b-1, c);
        }
        else {
            int idx; cin >> idx;
            cout << seg.query(idx-1, idx-1) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}