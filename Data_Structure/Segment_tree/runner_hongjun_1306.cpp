// Problem: BOJ 1306

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct segmentTree
{
    vector<int> arr;
    vector<int> tree;
    int sz;
    int dValue;

    int merge(int a, int b) { return max(a, b); }

    void init(int node, int s, int e) {
        if (s == e) tree[node] = arr[s];
        else {
            int m = (s+e) / 2;
            init(2*node, s, m);
            init(2*node + 1, m+1, e);
            tree[node] = merge(tree[2*node], tree[2*node + 1]);
        }
    }

    segmentTree(const vector<int>& a) {
        arr = a;
        sz = arr.size();
        int h = (int)ceil(log2(sz));
        int tree_sz = (1 << (h+1));
        tree = vector<int>(tree_sz);
        dValue = 0;
        init(1, 0, sz-1);
    }

    int query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return dValue;
        if (l <= s && e <= r) return tree[node];

        int m = (s + e) / 2;
        return merge(query(2*node, s, m, l, r), query(2*node+1, m+1, e, l, r));
    }

    int query(int l, int r) { return query(1, 0, sz-1, l, r); }

};

void solve() {
    int N, M; cin >> N >> M;
    vector<int> arr(N); for(int i = 0; i < N; i++) cin >> arr[i];
    segmentTree seg{arr};
    M--;
    int idx = M;
    while (idx < N-M)
    {
        cout << seg.query(idx-M, idx+M) << " ";
        idx ++;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}