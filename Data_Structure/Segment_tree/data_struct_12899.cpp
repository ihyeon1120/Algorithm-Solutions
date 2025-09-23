// Problem: BOJ 12899

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2000001;

struct segment {
    vector<int> tree;
    int sz;

    segment() {
        sz = MAXN;
        int h = (int)ceil(log2(sz));
        int tree_sz = (1 << (h + 1));
        tree = vector<int>(tree_sz, 0);
    }

    void update(int node, int s, int e, int idx, int k) {
        if (idx < s || e < idx) return;
        if (s == e) {
            tree[node] += k;
            return;
        }
        int m = (s + e) / 2;
        update(2*node, s, m, idx, k);
        update(2*node + 1, m + 1, e, idx, k);
        tree[node] = tree[2 * node] + tree[2 * node + 1]; 
    }

    int query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[node];
        int m = (s + e)  / 2;
        return query(2*node, s, m, l, r) + query(2 * node + 1, m + 1, e, l, r);
    }

    // x번째 원소를 찾는 함수
    int find_kth(int node, int s, int e, int x) {
        // 1. 리프 노드에 도달했다면, 그 위치가 정답
        if (s == e) {
            return s;
        }

        int m = (s + e) / 2;
        int left_child_count = tree[2 * node];

        // 2. x가 왼쪽 자식의 개수보다 작거나 같으면, 왼쪽으로 탐색
        if (x <= left_child_count) {
            return find_kth(2 * node, s, m, x);
        }
        // 3. x가 왼쪽 자식의 개수보다 크면, 오른쪽으로 탐색
        else {
            // 오른쪽에서는 (x - 왼쪽 자식 개수)번째 원소를 찾으면 됨
            return find_kth(2 * node + 1, m + 1, e, x - left_child_count);
        }
    }

    void update(int idx, int k) { update(1, 0, sz-1, idx, k); }
    int query(int l, int r) { return query(1, 0, sz-1, l, r); }
    int find_kth(int x) { return find_kth(1, 0, sz-1, x); }
};

void solve() {
    int n; cin >> n;
    segment seg;
    while (n--) {
        int t, x; cin >> t >> x;
        if (t == 1) {
            seg.update(x, 1);
        }
        else {
            int res = seg.find_kth(x);
            seg.update(res, -1);
            cout << res << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}