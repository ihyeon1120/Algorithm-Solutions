// Problem: BOJ 11057

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1001;
const int MOD = 10007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // dp[i][j] = 수의 길이가 1이면서 0~j로 끝나는 오르막수의 개수 (누적합)
    vector<vector<int>> dp(MAXN, vector<int>(10, 0));

    dp[1][0] = 1;
    for (int j = 1; j < 10; ++j) {
        dp[1][j] = dp[1][j-1] + 1; 
    }
    for (int i = 2; i < MAXN; ++i) {
        dp[i][0] = dp[i-1][0];
        for (int j = 1; j < 10; ++j) {
            // j로 끝나는 개수 = dp[i-1][j] -> 0~j로 끝나는 거에 맨 뒤에 j를 붙인다 생각
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % MOD;
        }
    }

    int n; cin >> n;
    cout << dp[n][9] << endl;

    return 0;
}