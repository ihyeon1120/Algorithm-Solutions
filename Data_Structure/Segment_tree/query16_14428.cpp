/*
 * Problem: BOJ 2042
 * Reference: https://www.acmicpc.net/source/95744722
 * Author: daniel604
 * * Key Idea: 세그먼트 트리를 구조체로 캡슐화한 코드를 배움
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

struct SegmentTree
{
    vector<ll> arr;
    vector<int> tree;
    int dValue;
    int sz;

    int merge(int a, int b) { 
        if (a == -1) return b;
        if (b == -1) return a;
        if (arr[a] <= arr[b]) return a;
        else return b;
    }

    SegmentTree(const vector<ll>& a){
        sz = a.size();
        arr = a;
        int h = (int)ceil(log2(sz));
        int tree_size = (1 << (h + 1));
        tree = vector<int>(tree_size);
        dValue = -1;
        init(1, 0, sz - 1);
    }
    
    void init(int node, int start, int end){
        if (start == end) tree[node] = start;
        else {
            int mid = (start + end) / 2;
            init(2*node, start, mid);
            init(2*node + 1, mid + 1, end);
            tree[node] = merge(tree[2*node], tree[2*node + 1]);
        }
    }

    void update(int node, int start, int end, int index, ll val){
        if (index < start || end < index) return;
        if (start == end){
            arr[index] = val;
            return;
        }
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, val);
		update(node * 2 + 1, mid + 1, end, index, val);
        tree[node] = merge(tree[2*node], tree[2*node + 1]);
    }

    int query(int node, int start, int end, int left, int right){
        if (right < start || end < left) return dValue;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        int lidx = query(2*node, start, mid, left, right);
        int ridx = query(2*node + 1, mid + 1, end, left, right);
        return merge(lidx, ridx);
    }
    void update(int index, ll val) {update(1, 0, sz-1, index, val);}
    int query(int left, int right) {return query(1, 0, sz-1, left, right);}
};

void solve(){

    int N, M; cin >> N;
    vector<ll> arr(N); for (int i = 0; i < N; i++) cin >> arr[i];
    SegmentTree seg {arr};
    cin >> M;

    while (M--){
        ll a, b, c; cin >> a >> b >> c;
        if (a == 1){
            seg.update(b-1, c);
        } else{
            cout << seg.query(b-1, c-1) + 1 << endl;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}