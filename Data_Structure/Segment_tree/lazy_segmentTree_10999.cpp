// Problem: BOJ 10999

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct LazySegmentTree {
    vector<ll> arr;
    vector<ll> tree;
    vector<ll> lazy;
    int dValue;
    int sz;

    ll merge(ll a, ll b) { return a + b; }

    void init(int node, int s, int e) {
        if (s == e) tree[node] = arr[s];
        else {
            int m = (s + e)/ 2;
            init(2*node, s, m);
            init(2*node + 1, m + 1, e);
            tree[node] = merge(tree[2*node], tree[2*node + 1]);
        }
    }

    LazySegmentTree(vector<ll> a) {
        arr = a;
        sz = sz(arr);
        int h = (int)ceil(log2(sz));
        int tree_sz = (1 << (h+1));
        tree = vector<ll>(tree_sz);
        lazy = vector<ll>(tree_sz, 0);
        dValue = 0;
        init(1, 0, sz-1);
    }

    void propagate(int node, int s, int e) {
        // lazy값이 있으면 lazy값 더해주기
        if (lazy[node] != 0) {
            tree[node] += (ll)(e - s + 1) * lazy[node];
            // 단말 노드가 아니라면 자식 노드에 lazy값 전파
            if (s != e) {
                lazy[2*node] += lazy[node];
                lazy[2*node + 1] += lazy[node];
            }
            // lazy값 적용, 전파 완료 후 lazy값 0으로 초기화
            lazy[node] = 0;
        }
        
    }

    void update_range(int node, int s, int e, int l, int r, ll val) {
        propagate(node, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            // tree[node] 값 변경
            tree[node] += (ll)(e - s + 1) * val;
            if (s != e) {
                // lazy[node]에 val를 업데이트 하는게 아닌 node의 자식에게 업데이트!
                // 이것때문에 5번 틀림..
                lazy[2*node] += val;
                lazy[2*node+1] += val;
            }
            return;
        }
        int m = (s + e) / 2;
        update_range(2*node, s, m, l, r, val);
        update_range(2*node + 1, m+1, e, l, r, val);
        tree[node] = merge(tree[2*node], tree[2*node + 1]);
    }

    ll query (int node, int s, int e, int l, int r) {
        propagate(node, s, e);
        if (r < s || e < l) return dValue;
        if (l <= s && e <= r) {
            return tree[node];
        }
        int m = (s + e) / 2;
        return merge(query(2*node, s, m, l, r), query(2*node + 1, m+1, e, l, r));
    }

    ll query(int l, int r) { return query(1, 0, sz-1, l, r); }
    void update_range(int l, int r, ll val) { update_range(1, 0, sz-1, l, r, val); }

};

void solve() {
    int N, M, K; cin >> N >> M >> K;
    vector<ll> a(N); for(int i = 0; i < N; i++) cin >> a[i];
    LazySegmentTree lazy_seg{a};
    M += K;
    while (M--)
    {
        int type; cin >> type;
        if (type == 1) {
            int left, right;
            ll val;
            cin >> left >> right >> val;
            if (left > right) swap(left, right);
            lazy_seg.update_range(left - 1, right - 1, val);
        } 
        
        else {
            int left, right; cin >> left >> right;
            if (left > right) swap(left, right);
            cout << lazy_seg.query(left - 1, right - 1) << endl;
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}