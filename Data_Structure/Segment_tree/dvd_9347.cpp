// Problem: BOJ 9345

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9;

// 각 구간의 최소와 최대가 구간 양 끝값과 같으면 true
struct segment_tree {
    vector<int> arr;
    vector<int> min_tree; // 최솟값을 저장할 트리
    vector<int> max_tree; // 최댓값을 저장할 트리
    int sz;
    
    // min_tree 초기화
    void init_min(int node, int s, int e) {
        if (s == e) min_tree[node] = arr[s];
        else {
            int m = (s + e) / 2;
            init_min(2*node, s, m);
            init_min(2*node + 1, m + 1, e);
            min_tree[node] = min(min_tree[2*node], min_tree[2*node+1]);
        }
    }
    
    // max_tree 초기화
    void init_max(int node, int s, int e) {
        if (s == e) max_tree[node] = arr[s];
        else {
            int m = (s + e) / 2;
            init_max(2*node, s, m);
            init_max(2*node + 1, m + 1, e);
            max_tree[node] = max(max_tree[2*node], max_tree[2*node+1]);
        }
    }

    segment_tree(const vector<int> &a) {
        arr = a;
        sz = sz(a);
        int h = (int)ceil(log2(sz));
        int tree_sz = (1 << (h+1));
        min_tree.resize(tree_sz);
        max_tree.resize(tree_sz);
        init_min(1, 0, sz-1);
        init_max(1, 0, sz-1);
    }
    
    // min_tree 업데이트
    void update_min(int node, int s, int e, int idx, int val) {
        if (idx < s || e < idx) return;
        if (s == e) {
            min_tree[node] = val;
            return;
        }
        int m = (s + e) / 2;
        update_min(2*node, s, m, idx, val);
        update_min(2*node + 1, m + 1, e, idx, val);
        min_tree[node] = min(min_tree[2*node], min_tree[2*node+1]);
    }
    
    // max_tree 업데이트
    void update_max(int node, int s, int e, int idx, int val) {
        if (idx < s || e < idx) return;
        if (s == e) {
            max_tree[node] = val;
            return;
        }
        int m = (s + e) / 2;
        update_max(2*node, s, m, idx, val);
        update_max(2*node + 1, m + 1, e, idx, val);
        max_tree[node] = max(max_tree[2*node], max_tree[2*node+1]);
    }

    void update(int idx, int val) {
        arr[idx] = val; // 원본 배열도 갱신
        update_min(1, 0, sz-1, idx, val);
        update_max(1, 0, sz-1, idx, val);
    }
    
    // min_tree 쿼리
    int query_min(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return INF;
        if (l <= s && e <= r) return min_tree[node];
        int m = (s + e) / 2;
        return min(query_min(2*node, s, m, l, r), query_min(2*node+1, m+1, e, l, r));
    }
    
    // max_tree 쿼리
    int query_max(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return -INF;
        if (l <= s && e <= r) return max_tree[node];
        int m = (s + e) / 2;
        return max(query_max(2*node, s, m, l, r), query_max(2*node+1, m+1, e, l, r));
    }

    bool query(int l, int r) {
        int min_val = query_min(1, 0, sz-1, l, r);
        int max_val = query_max(1, 0, sz-1, l, r);
        return (min_val == l && max_val == r);
    }
};

void solve() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) arr[i] = i;
        
        segment_tree seg{arr};

        while(k--) {
            int q, a, b; cin >> q >> a >> b;
            if (q == 0) { // update
                // 원래 배열 값도 바꿔줘야 함
                int val_a = seg.arr[a];
                int val_b = seg.arr[b];
                seg.update(a, val_b);
                seg.update(b, val_a);
            }
            else { // query
                cout << (seg.query(a, b) ? "YES" : "NO") << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}