// Problem: BOJ 13925

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = pow(10, 9) + 7;

struct lazy_segment {
    vector<ll> lazy_add;
    vector<ll> lazy_mul;
    vector<ll> tree;
    vector<ll> arr;
    int sz;
    
    ll merge(ll a, ll b) { return a + b; }

    void init(int node, int s, int e) {
        if (s == e) tree[node] = arr[s];
        else {
            int m = (s + e) / 2;
            init(2 * node, s, m);
            init(2 * node + 1, m + 1, e);
            tree[node] = merge(tree[2*node], tree[2*node+1]);
        }
    }

    lazy_segment(const vector<ll> &a) {
        arr = a;
        sz = sz(arr);
        int h = (int)ceil(log2(sz));
        int tree_sz = (1 << (h + 1));
        lazy_add = vector<ll>(tree_sz, 0);
        lazy_mul = vector<ll>(tree_sz, 1);
        tree = vector<ll>(tree_sz);
        init(1, 0, sz-1);
    }
    
    void propagate(int node, int s, int e) {
        if (lazy_mul[node] != 1 || lazy_add[node] != 0) {
            tree[node] = lazy_mul[node] * tree[node] + (e - s + 1) * lazy_add[node];
            if (s != e) {
                lazy_add[2*node] += lazy_add[node];
                lazy_add[2*node + 1] += lazy_add[node];
                lazy_mul[2*node] *= lazy_mul[node];
                lazy_mul[2*node + 1] *= lazy_mul[node];
            }
            lazy_add[node] = 0;
            lazy_mul[node] = 1;
        }
    }


    // l ~ r까지 k값으로 바꾸기 
    void update3(int node, int s, int e, int l, int r, int k) {

    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}