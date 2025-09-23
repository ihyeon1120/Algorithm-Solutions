// Problem: BOJ 1904

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1000001;
const int MOD = 15746;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> dp(MAXN, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < MAXN; ++i) {
        // i-1개에서는 1밖에 붙일 수 없으니 그 경우의 수는 dp[i-1]
        // i-2개에서는 1을 붙이면 겹치는 경우가 생기니 0밖에 붙일 수 없음 그 경우의 수는 dp[i-2]
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= MOD;
    }

    int n ; cin >> n;
    cout << dp[n] << endl;

    return 0;
}