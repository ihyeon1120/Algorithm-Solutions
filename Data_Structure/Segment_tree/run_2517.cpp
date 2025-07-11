// Problem: BOJ 2517
/*
아이디어: 
트리의 값에는 사람의 수를 저장
트리 단말노드는 속도순으로 정렬했을 때의 맞는 인덱스 값에 저장 -> 이걸로 쿼리를 부를 수 있음 나보다 빠른 사람들이 몇 명있는지를 셀 수 있음
*/

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
    vector<ll> arr;
    vector<int> tree;
    int sz;
    int dValue;

    int merge(int a, int b) { return a + b; }

    segmentTree(const vector<ll>& a) {
        arr = a;
        sz = sz(arr);
        int h = (int)ceil(log2(sz));
        int tree_sz = (1 << (h+1));
        tree = vector<int>(tree_sz, 0);
        dValue = 0;
    }

    void update(int node, int s, int e, int idx) {
        if (idx < s || e < idx) return;
        if (s == e) tree[node] = 1;
        else {
            int m = (s+e) / 2;
            update(2*node, s, m, idx);
            update(2*node+1, m+1, e, idx);
            tree[node] = merge(tree[2*node], tree[2*node+1]);
        }
    } 

    int query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return dValue;
        if (l <= s && e <= r) return tree[node];
        int m = (s+e) / 2;
        return merge(query(2*node, s, m, l, r), query(2*node+1, m+1, e, l, r));
    }
    void update(int idx) { update(1, 0, sz-1, idx); }
    int query(int l, int r) { return query(1, 0 , sz-1, l, r); }
};

vector<ll> sorted;

int binary_search(ll val) {
    int left = 0;
    int right = sz(sorted);
    int mid;
    while(left <= right) {
        mid = (left + right) / 2;
        if (sorted[mid] == val) break;
        else if (sorted[mid] < val) left = mid+1;
        else right = mid - 1;
    }
    return mid;
}

void solve() {
    int n; cin >> n;
    vector<ll> arr(n); for(int i = 0; i < n; i++) cin >> arr[i];
    segmentTree seg{arr};
    sorted = arr;
    sort(all(sorted));
    for(int i = 0; i < n; i ++) {
        int idx = binary_search(arr[i]);
        cout << seg.query(idx  + 1, n-1) + 1 << endl;
        seg.update(idx);
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}