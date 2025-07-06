#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct LazyPropagation
{
    vector<ll> arr;
    vector<ll> lazy;
    vector<ll> tree;
    int dValue;
    int sz;

    ll merge(ll a, ll b) { return a + b; }

    void init(int node, int s, int e) {
        if (s == e) tree[node] = arr[s];
        else {
            int m = (s + e)/ 2;
            init(2*node, s, m);
            init(2*node + 1, m + 1, e);
            tree[node] = merge(tree[2*node], tree[2*node + 1]);
        }
    }

    LazyPropagation(vector<ll> a) {
        arr = a;
        sz = sz(arr);
        int h = (int)ceil(log2(sz));
        int tree_sz = (1 << (h+1));
        tree = vector<ll>(tree_sz);
        lazy = vector<ll>(tree_sz, 0);
        dValue = 0;
        init(1, 0, sz-1);
    }

    void propagate(int node, int s, int e) {
        if (lazy[node] != 0) {
            tree[node] += (e - s + 1) * lazy[node];
            // 자식 노드로 lazy값 전파
            if (s != e) {
                lazy[2*node] = merge(lazy[2*node], lazy[node]);
                lazy[2*node + 1] = merge(lazy[2*node + 1], lazy[node]);
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int start, int end, int left, int right, int val) {
        propagate(node, start, end);
        if (right < start || end < left) return;
        if (left <= start && end <= right) {
            tree[node] += (end - start + 1) * (val);
            if (start != end) {
                lazy[2*node] += val;
                lazy[2*node+1] += val;
            }
            return;
        }
        int mid = (start + end) / 2;
        update(2*node, start, mid, left, right, val);
        update(2*node+1, mid+1, end, left, right, val);
        tree[node] = merge(tree[2*node], tree[2*node + 1]);
    }

    ll query(int node, int start, int end, int left, int right) {
        propagate(node, start, end);
        if (end < left || right < start) return dValue;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        return merge(query(2*node, start, mid, left, right), query(2*node+1, mid+1, end, left, right));
    }

};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}