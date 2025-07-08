// Problem: BOJ 1003

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int dp[41][2] = {0};

void ps() {
    for(int i = 2; i < 41; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }
}

void solve() {
    int t; cin >> t;
    
    dp[0][0] = 1;
    dp[1][1] = 1;
    ps();
    while (t--){
        int n; cin >> n;
        cout << dp[n][0] << " " << dp[n][1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}