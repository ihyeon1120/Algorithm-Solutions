// Problem: BOJ 17353

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct lazy_segment {
    vector<ll> lazy;
    vector<ll> tree;
    vector<ll> diff_arr;
    int sz;
    int dValue;
    /*
        배열: 3 8 6 9 5
        차분 배열: 3 5 -2 3 -4
        차분 배열 누적합: 3 8 6 9 5 = 원본 배열
        원본배열에 각 인덱스만큼 증가 시키기
        4 10 9 13 10
        4 6 -1 4 -3 -> 원본 차분 배열에서 +1
        원래는 l, r에 따라 복잡하게 증가시켜여야했던 문제를 차분 배열을 통해 l, r구간에 +1만 해주고 원본 값은 누적합으로 반환
    */

    ll merge(ll a, ll b) { return a + b; }

    void init(int node, int s, int e) {
        if (s == e) tree[node] = diff_arr[s];
        else {
            int m = (s + e) / 2;
            init(2 * node, s, m);
            init(2 * node + 1, m + 1, e);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    lazy_segment(const vector<ll> &a) {
        sz = sz(a);
        diff_arr = vector<ll>(sz);
        diff_arr[0] = a[0];
        for (int i = 1; i < sz; i++) 
            diff_arr[i] = a[i] - a[i-1];
        int h = (int)ceil(log2(sz));
        int tree_sz = (1 << (h + 1));
        tree.resize(tree_sz);
        lazy = vector<ll>(tree_sz, 0);
        init(1, 0, sz-1);
    }

    void propagate(int node, int s, int e) {
        if (lazy[node] != 0) {
            tree[node] += (e - s + 1) * lazy[node];
            if (s != e) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update_range(int node, int s, int e, int l, int r, int val) {
        propagate(node, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            lazy[node] += val;
            propagate(node, s, e);
            return;
        }
        int m = (s + e) / 2;
        update_range(2 * node, s, m, l, r, val);
        update_range(2 * node + 1, m + 1, e, l, r, val);
        tree[node] = merge(tree[2*node], tree[2*node + 1]);
    }

    ll query(int node, int s, int e, int l, int r) {
        propagate(node, s, e);
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[node];
        int m = (s + e) / 2;
        return merge(query(2 * node, s, m, l, r), query(2 * node + 1, m + 1, e, l , r));
    }

    void update_range(int l, int r, int val) { update_range(1, 0, sz-1, l, r, val); }
    // 차분배열의 누적합을 쿼리를 통해 logN으로 수행
    ll query(int l, int r) { return query(1, 0, sz-1, l, r); }
    
};

void solve() {
    int n; cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    lazy_segment seg{arr};
    
    int m; cin >> m;
    while(m--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r; cin >> l >> r;
            l--; r--;

            seg.update_range(l, l, 1);
            if (l + 1 <= r) {
                seg.update_range(l + 1, r, 1);
            }
            // 3. B[r+1]에 -(r-l+1) 하기
            if (r + 1 < n) {
                seg.update_range(r + 1, r + 1, -(r - l + 1));
            }

        } else if (t == 2) {
            int x; cin >> x;
            cout << seg.query(0, x - 1) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}