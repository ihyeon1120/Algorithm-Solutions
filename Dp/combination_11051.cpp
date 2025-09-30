// Problem: BOJ 11051

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 10007;
const int MAXN = 1001;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> dp(MAXN, vector<int>(MAXN));
    dp[1][0] = 1; dp[1][1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        dp[i][0] = 1;
        for (int j = 1; j < i; ++j) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
        }
        dp[i][i] = 1;
    }
    int x, y; cin >> x >> y;
    cout << dp[x][y];

    return 0;
}