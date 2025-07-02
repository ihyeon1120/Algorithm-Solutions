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
    vector<ll> tree;
    ll dValue;
    int sz;

    ll merge(ll a, ll b) { return (a + b); }

    SegmentTree(int sz) {
		vector<ll> tmp(sz, 0ll);
		SegmentTree{tmp};
	}

    SegmentTree(const vector<ll>& a){
        sz = a.size();
        arr = a;
        int h = (int)ceil(log2(sz));
        // 비트 연산자를 통해 2^x 를 구하는 것 배움
        int tree_size = (1 << (h + 1)); // 2^(h+1)
        tree = vector<ll>(tree_size);
        dValue = 0;
        init(1, 0, sz - 1);
    }
    
    void init(int node, int start, int end){
        if (start == end) tree[node] = arr[start];
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
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, val);
		update(node * 2 + 1, mid + 1, end, index, val);
        tree[node] = merge(tree[2*node], tree[2*node + 1]);
    }

    ll query(int node, int start, int end, int left, int right){
        if (right < start || end < left) return dValue;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        ll lsum = query(2*node, start, mid, left, right);
        ll rsum = query(2*node + 1, mid + 1, end, left, right);
        return merge(lsum, rsum);
    }
    void update(int index, ll val) {update(1, 0, sz-1, index, val);}
    ll query(int left, int right) {return query(1, 0, sz-1, left, right);}
};

void solve(){

    int N, M, K; cin >> N >> M >> K;
    vector<ll> a(N); for (int i = 0; i < N; i++) cin >> a[i];
    SegmentTree seg {a};
    M += K;
    while (M--){
        ll a, b, c; cin >> a >> b >> c;
        if (a == 1){
            seg.update(b-1, c);
        } else{
            cout << seg.query(b-1, c-1) << endl;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}