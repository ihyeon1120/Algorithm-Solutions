// Problem: BOJ 11066

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int h = ceil(log2(n));
        ll ans = 0;
        vector<vector<int>> dp(h+1);
        for (int i = 0; i < n; ++i) {
            int k; cin >> k;
            dp[0].push_back(k);
        }
        sort(all(dp[0]), greater<>());
        for (int r = 1; r < h+1; ++r) {
            for (int c = 0; c < sz(dp[r-1]); c += 2) {
                if (c + 1 >= sz(dp[r-1])) {
                    dp[r].push_back(dp[r-1][c]);
                    ans += dp[r-1][c];
                    continue;
                }
                dp[r].push_back(dp[r-1][c] + dp[r-1][c+1]);
                ans += dp[r-1][c] + dp[r-1][c+1];
            }
        }
        cout << ans << endl;
    }
    return 0;
}