// Problem: BOJ 

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

map<ll, ll> memo;
struct seg {
    vector<ll> tree;
    vector<ll> a;
    int sz;

    void init(int node, int s, int e) {
        if (s == e) tree[node] = a[s];
        else {
            int m = (s + e) / 2;
            init(2*node, s, m);
            init(2*node + 1, m + 1, e);
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }

    seg(const vector<ll> &arr) {
        a = arr;
        sz = sz(a);
        int h = (int)ceil(log2(sz));
        int tree_sz = (1 << (h+1));
        tree = vector<ll>(tree_sz);
        init(1, 0, sz-1);
    }

    ll query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[node];
        int m = (s + e) / 2;
        return query(2*node, s, m, l, r) + query(2*node + 1, m + 1, e, l, r);
    }

    ll query(int l, int r) { return query(1, 0, sz-1, l, r); }

};

ll fill_memo(ll n) {
    // 기저 사례 추가
    if (n <= 1) return 0;
    
    // 안전한 키 확인 방식으로 변경
    if (memo.count(n)) {
        return memo[n];
    }
    
    ll half = n / 2;
    ll next_val;

    if (half <= 1) {
        next_val = 0;
    } else {
        next_val = fill_memo(half + 1);
    }
    
    // 계산한 값을 return 하도록 수정
    return memo[n] = 1 + next_val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        memo.clear();
        int n, q; cin >> n >> q;
        vector<ll> arr(n);
        for (int i = 0; i < n; ++i) {
            ll k; cin >> k;
            arr[i] = fill_memo(k);
        }
        seg s {arr};
        while(q--) {
            int l, r; cin >> l >> r;
            cout << s.query(l-1, r-1) << endl;
        }
    }
    return 0;
}