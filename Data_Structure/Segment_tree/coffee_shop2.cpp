#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// N, Q <= 10**6, 

struct coffee_shop2
{
    vector<ll> arr;
    vector<ll> tree;
    int sz;
    int dValue;

    ll merge(ll a, ll b){ return (a+b); }

    void init(int node, int start, int end){
        if (start == end) tree[node] = arr[start];
        else{
            int mid = (start + end) / 2;
            init(2*node, start, mid);
            init(2*node + 1, mid + 1, end);
            tree[node] = merge(tree[2*node], tree[2*node + 1]);
        }
    }

    coffee_shop2(vector<ll> a){
        sz = a.size();
        arr = a;
        int h = (int)ceil(log2(sz));
        int tree_size = (1 << (h+1));
        tree = vector<ll>(tree_size);
        dValue = 0;
        init(1, 0, sz-1);
    }

    void update(int node, int start, int end, int index, ll val){
        if (index < start || end < index) return;
        if (start == end) {
            tree[node] = val;
            arr[index] = val;
            return;
        }
        int mid = (start + end) / 2;
        update(2*node, start, mid, index, val);
        update(2*node + 1, mid + 1, end, index, val);
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

    ll query(int left, int right) { return query(1, 0, sz-1, left, right); }
    void update(int index, ll val) { return update(1, 0, sz-1, index, val); }

};

void solve(){
    int N, Q; cin >> N >> Q;
    vector<ll> arr(N); for(int i = 0; i<N; i++) cin >> arr[i];
    coffee_shop2 seg {arr};
    while (Q--)
    {
        int x, y, a, b; cin >> x >> y >> a >> b;
        if (x > y) swap(x, y);
        cout << seg.query(x-1, y-1) << endl;
        seg.update(a-1, b);
    }
    
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}