// Problem: BOJ 2748

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int MAXN = 91;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> dp(MAXN, 0);
    dp[1] = 1;
    for (int i = 2; i < MAXN; ++i)
        dp[i] = dp[i-1] + dp[i-2];

    int n; cin >> n;
    cout << dp[n] << endl;
    return 0;
}