// Problem: BOJ 1309

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 9901;
const int MAXN = 100001;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    /*
        dp[i][0]는 2*i 동물원에 사자를 배치하는 경우, i행에는 00 (사자를 채우지 않는 경우)
        dp[i][1]은 i행에 10
        dp[i][2]는 i행에 01
    */
    vector<vector<int>> dp(MAXN, vector<int>(3, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;

    for (int i = 2; i < MAXN; ++i) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % MOD;
    }
    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;
    return 0;
}