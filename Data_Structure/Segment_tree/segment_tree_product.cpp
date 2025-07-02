#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;

struct segment_tree_product
{
    vector<ll> arr;
    vector<ll> tree;
    ll dValue;
    int sz;

    ll merge(ll a, ll b) { return (a * b) % MOD; }

    segment_tree_product(const vector<ll>& a){
        sz = a.size();
        arr = a;
        int h = (int)ceil(log2(sz));
        int tree_size = (1<<(h+1)); // 2^(h+1)
        tree = vector<ll>(tree_size);
        dValue = 1; //곱하기니까 디폴트는 1
        init(1, 0, sz-1);
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
        if (start == end) {
            tree[node] = val;
            arr[start] = val;
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
        ll lproduct = query(2*node, start, mid, left, right);
        ll rproduct = query(2*node + 1, mid + 1, end, left, right);
        return merge(lproduct, rproduct);
    }

    void update(int index, ll val) {update(1, 0, sz - 1, index, val);}
    ll query(int left, int right) {return query(1, 0, sz-1, left, right);}
};

void solve(){
    int N, M, K; cin >> N >> M >> K;
    vector<ll> a(N); for (int i = 0; i < N; i ++) cin >> a[i];
    segment_tree_product seg{a};
    M += K;
    while (M--)
    {
        int a, b, c; cin >> a >> b >> c;
        if (a == 1){
            seg.update(b-1, c);
        } else {
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