// Problem: BOJ 13544

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct merge_sort_tree {
    int sz;
    vector<ll> arr;
    vector<vector<ll>> tree;
    int dValue;

    void merge_node(const vector<ll> &l, const vector<ll> &r, int node) {
        tree[node] = vector<ll>(sz(l) + sz(r));
        merge(all(l), all(r), tree[node].begin());
    }

    void init(int node, int s, int e) {
        if (s == e) tree[node].push_back(arr[s]);
        else {
            int mid = (s + e) / 2;
            init(2*node, s, mid);
            init(2*node+1, mid+1, e);
            merge_node(tree[2*node], tree[2*node+1], node);
        }
    }

    merge_sort_tree(const vector<ll> &a) {
        arr = a;
        sz = sz(a);
        int h = (int)ceil(log2(sz));
        int tree_sz = (1 << (h+1));
        tree = vector<vector<ll>>(tree_sz);
        dValue = 0;
        init(1, 0, sz-1);
    }

    int query(int node, int s, int e, int l, int r, ll x) {
        if (r < s || e < l) return dValue;
        if (l <= s && e <= r) {
            return tree[node].end() - upper_bound(all(tree[node]), x);
        }
        int mid = (s + e) / 2;
        int left = query(2*node, s, mid, l, r, x);
        int right = query(2*node+1, mid+1, e, l, r, x);
        return left + right;
    }
    int query(int l, int r, ll x) { return query(1, 0, sz-1, l, r, x); }
};

void solve() {
    int n; cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    merge_sort_tree mst{arr};
    int m; cin >> m;
    int last_ans = 0;
    while(m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        int l = a ^ last_ans;
        int r = b ^ last_ans;
        int x = c ^ last_ans;
        last_ans = mst.query(l - 1, r - 1, x);
        cout << last_ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}