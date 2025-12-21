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
    int n, m, c; cin >> n >> m >> c;
    int ans = 0;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];
    while(n--) {
        ll t = 0;
        for (int i = 0 ; i < m; ++i) {
            int a; cin >> a;
            t += a * b[i];
        }
        t += c;
        if (t > 0) ans ++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}