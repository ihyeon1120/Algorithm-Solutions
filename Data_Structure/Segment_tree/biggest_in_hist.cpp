#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct biggest_in_hist
{
    // n <= 10**6, h <= 10**9
    // tree[node] -> 구간 내의 높이의 최소값을 갖고 있는 '인덱스 저장'
    vector<ll> arr;
    vector<ll> tree;
    int sz;
    ll dValue;
    ll ans;

    ll merge(ll a, ll b){
        if (a == -1) return b;
        if (b == -1) return a;
        if (arr[a] <= arr[b]){ return a; }
        else { return b; }
    }

    biggest_in_hist(const vector<ll>& a){
        sz = a.size();
        arr = a;
        int h = (int)ceil(log2(sz));
        int tree_size = (1 << (h + 1));
        tree = vector<ll>(tree_size);
        dValue = -1;
        ans = 0;
        init(1, 0, sz-1);
    }

    void init(int node, int start, int end){
        if (start == end) {
            tree[node] = start;
        } else {
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
        ll lmin_idx = query(2*node, start, mid, left, right);
        ll rmin_idx = query(2*node + 1, mid + 1, end, left, right);
        return merge(lmin_idx, rmin_idx);
    }

    ll solve(int left, int right){
        if (left <= right){
            // 최소값의 인덱스로 분할 정복
            int min_idx = query(left, right);

            ll area = arr[min_idx] * (right - left + 1);
            ll left_area = solve(left, min_idx - 1);
            ll right_area = solve(min_idx + 1, right);

            return max({area, left_area, right_area});
        } else {
            return 0;
        }
    }

    ll query(int left, int right) { return query(1, 0, sz-1, left, right); }
    ll solve(){ return solve(0, sz-1); }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    vector<ll> a(N); for(int i = 0; i< N; i++) cin >> a[i];
    biggest_in_hist seg{a};
    cout << seg.solve() << endl;

    return 0;
}