// Problem: BOJ 10844

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 102;
const ll MOD = 1000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<ll>> dp(MAXN, vector<ll>(10, 0));
    for (int i = 1; i <= 9; ++i)
        dp[1][i] = 1;
    
    for (int i = 2; i < MAXN; ++i) {
        for (int j = 1; j < 9; ++j) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
        }
        dp[i][0] = (dp[i-1][1]) % MOD;
        dp[i][9] = (dp[i-1][8]) % MOD;
    }

    int n; cin >> n;

    ll ans = 0;
    for (int i = 0; i <= 9; ++i) {
        ans = (ans + dp[n][i]) % MOD;
    }
    cout << ans << endl;
    return 0;
}