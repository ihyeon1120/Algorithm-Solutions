#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 998244353;

void solve() {
    int n ,m; cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);
    vector<ll> prefix(n+1, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    sort(all(a));
    for (int i = 0; i < n; ++i) {
        prefix[i+1] = (prefix[i] % MOD) + (a[i] % MOD);
    }
    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        auto it = lower_bound(all(a), b[i]);
        int idx = it - a.begin();
        ll term_left = (b[i] % MOD) * idx % MOD;
        ll left_sum = (term_left - prefix[idx] + MOD) % MOD;
        
        ll range_sum = (prefix[n] - prefix[idx] + MOD) % MOD;
        ll term_right = (b[i] % MOD) * (n - idx) % MOD;
        ll right_sum = (range_sum - term_right + MOD) % MOD;
        ans += (left_sum + right_sum) % MOD;
    }
    cout << ans % MOD << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}