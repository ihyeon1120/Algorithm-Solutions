// Problem: BOJ 2243

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

#define MAX_SIZE 1000001

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// 맛의 좋음을 x라 할 때 arr[x]는 맛의 좋음 x인 사탕의 개수임. -> 세그먼트 트리에는 각 맛에 따라 사탕의 개수를 저장

struct SegmentTree
{
    vector<ll> arr;
    vector<ll> tree;
    int dValue;
    int sz;

    ll merge(ll a, ll b) { return a + b; }

    void init(int node, int s, int e){
        if (s == e) tree[node] = arr[s];
        else {
            int m = (s + e) / 2;
            init(2*node, s, m);
            init(2*node + 1, m + 1, e);
            tree[node] = merge(tree[2*node], tree[2*node + 1]);
        }
    }

    SegmentTree(vector<ll> a){
        arr = a;
        sz = sz(arr);
        int h = (int)ceil(log2(sz));
        int tree_sz = (1 << (h+1));
        tree = vector<ll>(tree_sz);
        dValue = 0;
        init(1, 0, sz-1);
    }

    void update(int node, int s, int e, int idx, ll val) {
        if (idx < s || e < idx) return;
        if (s == e) {
            // += val을 하는 이유는 val만큼 사탕 상자에 넣거나 빼는 연산이기 때문에.
            tree[node] += val;
            arr[s] += val;
            return;
        }
        int m = (s + e) / 2;
        if (idx <= m) {
            update(2*node, s, m, idx, val);
        } else {
            update(2*node+1, m+1, e, idx, val);
        }
        tree[node] = merge(tree[2*node], tree[2*node + 1]);
    }

    ll query(int node, int s, int e, int left, int right) {
        if (right < s || e < left) return dValue;
        if (left <= s && e <= right) return tree[node];

        int m = (s+e)/ 2;
        return merge(query(2*node, s, m, left, right), query(2*node + 1, m+1, e, left, right));
    }

    int ps(int node, int s, int e, int val){
        if (s == e) {
            return s;
        }
        int m = (s + e) / 2;
        ll lsum = tree[2*node];
        // 왼쪽의 부분합보다 작으면 왼쪽에서 꺼낼 수 있음.
        // 왼쪽의 부분합보다 크면 왼쪽의 사탕 개수가 부족함으로 오른쪽에서 꺼냄.
        if (val <= lsum) {
            return ps(2*node, s, m, val);
        } else {
        // 오른쪽으로 가면 val - lsum을 통해 다음번 탐색을 할 수 있게 조정
            return ps(2*node + 1, m+1, e, val - lsum);
        }
    }

    void update(int idx, int val) { return update(1, 0 ,sz-1, idx, val); }
    ll query(int left, int right) { return query(1, 0, sz-1, left, right); }
    int ps(int val) { return ps(1, 0, sz-1, val); }

};
#include <sstream>
void solve() {

    int N; cin >> N;
    vector<ll> a(MAX_SIZE, 0);
    SegmentTree seg {a};
    while (N--){
        int a; cin >> a;
        if (a == 1) {
            int b; cin >> b;
            int idx = seg.ps(b);
            cout << idx + 1 << endl;
            seg.update(idx, -1);
        } else {
            int b, c; cin >> b >> c;
            seg.update(b-1, c);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}