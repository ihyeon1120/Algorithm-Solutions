// Problem: BOJ 2193

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 91;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pll> dp(MAXN, {0, 0});
    dp[1] = {0, 1};
    dp[2] = {1, 0};
    // dp[3] = {1, 1};
    // dp[4] = {2, 1};
    // dp[5] = {3, 2};

    for (int i = 3; i < MAXN; i++) {
        // 끝 자리가 1이면 다음에 오는건 무조건 0
        dp[i].first += dp[i-1].second;
        // 끝 자리가 0이면 다음에 오는건 0, 1 둘다 증가
        dp[i].first += dp[i-1].first;
        dp[i].second += dp[i-1].first;
    }

    int n; cin >> n;
    cout << dp[n].first + dp[n].second << endl;

    return 0;
}