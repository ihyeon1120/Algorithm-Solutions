#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Fenwick {
    vector<ll> fw;
    int sz;

    void update(int i, ll v) {
        for (; i <= sz; i += (i & -i)) {
            fw[i] += v;
        }
    }

    ll query(int i) {
        ll ret = 0;
        for (; i > 0; i -= (i & -i))
            ret += fw[i];
        return ret;
    }

    Fenwick(const vector<ll> &arr) {
        sz = sz(arr);
        fw = vector<ll>(sz+1, 0);
        for (int i = 1; i <= sz; ++i) {
            update(i, arr[i-1]);
        }
    }
};

void solve() {
    int n; cin >> n;
    vector<ll> arr(n+1, 0);
    vector<ll> diff(n+1, 0);
    for (int i = 0; i < n; ++i) cin >> arr[i+1];
    for (int i = 0; i < n; ++i ){
        diff[i+1] = arr[i+1] - arr[i];
    }
    Fenwick f(vector<ll>(diff.begin()+1, diff.end()));
    int m; cin >> m;
    while(m--) {
        int type; cin >> type;
        if (type == 1) {
            int i, j; cin >> i >> j;
            ll k; cin >> k;
            f.update(i, k);
            f.update(j+1, -k);
        }
        else {
            int i; cin >> i;
            cout << f.query(i) << endl;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}