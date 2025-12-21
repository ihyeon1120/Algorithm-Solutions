// Problem: BOJ 2104

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct min_seg {

    vector<ll> tree;
    vector<ll> arr;
    int sz;
    ll dValue;

    ll merge(ll a, ll b) {
        return min(a, b);
    }

    void init(int node, int s, int e) {
        if (s == e) tree[node] = arr[s];
        else {
            int m = (s + e) / 2;
            init(2*node, s, m);
            init(2*node + 1, m + 1, e);
            tree[node] = merge(tree[2*node], tree[2*node + 1]);
        }
    }

    min_seg(const vector<ll> &a) {
        arr = a;
        sz = sz(a);
        int h = (int)ceil(log2(sz));
        int tree_sz = (1 << (h+1));
        tree = vector<ll>(tree_sz);
        dValue = LONG_LONG_MAX;
        init(1, 0, sz-1);
    }

    ll query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return dValue;
        if (l <= s && e <= r) return tree[node];
        int m = (s + e) / 2;
        return merge(query(2*node, s, m, l, r), query(2*node + 1, m + 1, e, l ,r));
    }

    ll query(int l, int r) { return query(1, 0, sz-1, l, r); }
};

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

    ll query(int node, int start, int end, int left, int right){
        if (right < start || end < left) return dValue;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        ll lsum = query(2*node, start, mid, left, right);
        ll rsum = query(2*node + 1, mid + 1, end, left, right);
        return merge(lsum, rsum);
    }
    ll query(int left, int right) {return query(1, 0, sz-1, left, right);}
};

struct max_seg {

    vector<ll> tree;
    vector<ll> a;
    int sz;

    void init(int node, int s, int e, SegmentTree &st, min_seg &ms) {
        if (s == e) tree[node] = a[s] * a[s];
        else {
            int m = (s + e) / 2;
            init(2*node, s, m, st, ms);
            init(2*node + 1, m + 1, e, st, ms);
            tree[node] = max({tree[2*node], tree[2*node+1], st.query(s, e) * ms.query(s, e)});
        }
    }
    
    max_seg(const vector<ll> &arr) {
        a = arr;
        sz = sz(a);
        int h = (int)ceil(log2(sz));
        int tree_sz = (1 << (h + 1));
        tree = vector<ll>(tree_sz);
        SegmentTree st{a};
        min_seg ms{a};
        init(1, 0, sz-1, st, ms);
    }

};

void solve() {
    int n; cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    max_seg max_s{arr};
    cout << max_s.tree[1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}