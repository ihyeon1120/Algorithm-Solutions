// Problem: BOJ 2775

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll dp[15][15];

void solve() {
    for (int i = 0; i < 15; i ++) dp[0][i] = i;
    for (int i = 1; i < 15; i ++) {
        int temp = 0;
        for (int j = 1; j <15; j ++) {
            temp += dp[i-1][j];
            dp[i][j] = temp;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    int n; cin >> n;
    while(n--) {
        int i, j; cin >> i >> j;
        cout << dp[i][j] << endl;
    }

    return 0;
}