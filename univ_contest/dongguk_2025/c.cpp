// Problem: C

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
    int p, m, c; cin >> p >> m >> c;
    ll x; cin >> x;
    ll ans = LONG_LONG_MAX;
    for (int i = 1; i <= p; ++i){
        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k <= c; ++k) {
                ans = min(ans, abs((i + j)*(j + k) - x));
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}