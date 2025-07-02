#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct segment_tree_min_max
{
    vector<ll> arr;
    vector<pll> tree;
    pll dValue;
    int sz;

    pll merge(pll a, pll b){
        ll min_val = min(a.first, b.first);
        ll max_val = max(a.second, b.second);
        return {min_val, max_val};
    }

    segment_tree_min_max(const vector<ll>& a){
        sz = a.size();
        arr = a;
        int h = (int)ceil(log2(sz));
        int tree_size = (1 << (h+1));
        tree = vector<pll>(tree_size);
        dValue = {LLONG_MAX, LLONG_MIN};
        init(1, 0, sz-1);
    }

    void init(int node, int start, int end){
        if (start == end) {
            tree[node].first = arr[start];
            tree[node].second = arr[start];
        } else {
            int mid = (start + end) / 2;
            init(2*node, start, mid);
            init(2*node + 1, mid + 1, end);
            tree[node] = merge(tree[2*node], tree[2*node + 1]);
        }
    }

    pll query(int node, int start, int end, int left, int right){
        if (right < start || end < left) return dValue;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        pll lpll = query(2*node, start, mid, left, right);
        pll rpll = query(2*node + 1, mid + 1, end, left, right);
        return merge(lpll, rpll);
    }
    pll query(int left, int right) {return query(1, 0, sz-1, left, right);}
};

void solve(){
    int N, M; cin >> N >> M;
    vector<ll> a(N); for(int i = 0; i < N; i++) cin >> a[i];
    segment_tree_min_max seg{a};

    while(M--){
        int a, b; cin >> a >> b;
        pll q = seg.query(a-1, b-1);
        cout << q.first << " " << q.second << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}