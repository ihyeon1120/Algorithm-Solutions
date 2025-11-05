// Problem: BOJ 15988

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MOD = 1000000009;
const int M = 1000001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // n < 100만
    vector<ll> dp(M);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < M; ++i) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
    }

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}