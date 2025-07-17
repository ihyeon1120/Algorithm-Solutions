// Problem: BOJ 3653

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct SegmentTree
{
    vector<ll> arr;
    vector<ll> tree;
    int sz;
    int dValue;

    ll merge(ll a, ll b) { return a + b ;}

    void init(int node, int s, int e) {
        if (s == e) tree[node] = arr[s];
        else { 
            int m = (s + e) / 2;
            init(2*node, s, m);
            init(2*node + 1, m + 1, e);
            tree[node] = merge(tree[2*node], tree[2*node + 1]);
        }
    }

    SegmentTree(int n, int m) {
        arr = vector<ll>(m, 0);
        vector<ll> temp(n, 1);
        // m + n 사이즈의 벡터 생성, m ~ m+n-1 까지 1로 채움
        // 0은 현재 인덱스에 dvd가 없다는 의미, 1은 현재 인덱스에 dvd가 있다는 의미
        arr.insert(arr.end(), all(temp));
        sz = sz(arr);
        int h = (int)ceil(log2(sz));
        int tree_sz = (1 << (h+1));
        tree = vector<ll>(tree_sz);
        dValue = 0;
        init(1, 0 , sz-1);
    }

    void update(int node, int s, int e, int idx, int val) {
        if (idx < s || e < idx) return;
        if (s == e) {
            tree[node] += val;
            arr[idx] += val;
            return;
        }
        int m = (s + e) / 2;
        update(2*node, s, m, idx, val);
        update(2*node+1, m+1, e, idx, val);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    ll query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return dValue;
        if (l <= s && e <= r) return tree[node];
        int m = (s+e) / 2;
        return merge(query(2*node, s, m, l, r), query(2*node + 1, m + 1, e, l, r));
    }
    void update(int idx, ll val) { update(1, 0, sz-1, idx, val); }
    ll query(int l, int r) { return query(1, 0, sz-1, l, r); }

};


void solve() {
    int n, m; cin >> n >> m;
    SegmentTree seg{n, m};
    vector<ll> idx(n+1); for (int i = 1; i <= n; i ++) idx[i] = m + i - 1;
    for (int i = 0; i < m; i ++) {
        int k; cin >> k;
        cout << seg.query(0, idx[k] - 1) << " ";
        seg.update(idx[k], -1);
        idx[k] = m - i - 1;
        seg.update(idx[k], 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        solve();
        cout << endl;
    }
    return 0;
}