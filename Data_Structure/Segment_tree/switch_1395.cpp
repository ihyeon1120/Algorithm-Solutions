// Problem: BOJ 1395

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct lazy_propagation{
    vector<int> arr;
    vector<int> tree;
    vector<int> lazy;
    int sz;
    int dValue;
    // 구간 내의 스위키가 켜져있는 개수
    int merge(int a, int b) { return a + b; } 

    void init(int node, int s, int e) {
        if (s == e) tree[node] = arr[s];
        else {
            int m = (s+e) / 2;
            init(2*node, s, m);
            init(2*node+1, m+1, e);
            tree[node] = merge(tree[2*node], tree[2*node + 1]);
        }
    }

    lazy_propagation(const vector<int>& a) {
        arr = a;
        sz = sz(arr);
        int h = (int)ceil(log2(sz));
        int tree_sz = (1 << (h+1));
        tree = vector<int>(tree_sz);
        lazy = vector<int>(tree_sz, 0);
        dValue = 0;
        init(1, 0, sz-1);
    }
    // lazy[node]가 1이 되면 tree[node] 값을 구간 내에 개수를 참고하여 반전 시키기 (구간: 0~5, 켜진 수 4 -> 2로 반전)
    void propagate(int node, int s, int e) {
        if(lazy[node] != 0) {
            tree[node] = (e - s + 1)  - tree[node];
            if (s != e) {
                // 스위치 연산을 바꾸는 것을 xor로 처리
                lazy[2*node] ^= lazy[node];
                lazy[2*node + 1] ^= lazy[node]; 
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int s, int e, int l, int r) {
        propagate(node, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            tree[node] = (e - s + 1) - tree[node];
            if (s != e) {
                lazy[2*node] ^= 1;
                lazy[2*node+1] ^= 1;
            }
            return;
        }
        int m = (s + e) / 2;
        update(2*node, s, m, l, r);
        update(2*node + 1, m+1, e, l, r);
        tree[node] = merge(tree[2*node], tree[2*node + 1]);
    }

    int query (int node, int s, int e, int l, int r) {
        propagate(node, s, e);
        if (r < s || e < l) return dValue;
        if (l <= s && e <= r) return tree[node];
        int m = (s+e) / 2;
        return merge(query(2*node, s, m, l, r), query(2*node+1, m+1, e, l, r));
    }

    void update(int l, int r) { update(1, 0, sz-1, l, r); }
    int query(int l, int r) { return query(1, 0, sz-1, l, r); }

};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> arr(n, 0);
    lazy_propagation seg{arr};
    while(m--) {
        int t; cin >> t;
        int a, b; cin >> a >> b;
        if (t) {
            cout << seg.query(a-1, b-1) << endl;
        } else {
            seg.update(a-1, b-1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}