// Problem: BOJ 1010

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// 0 < N <= M < 30
const int MAXN = 30;

vector<vector<ll>> dp;

void solve() {
    dp = vector<vector<ll>>(MAXN, vector<ll>(MAXN, 0));
    for (int i = 0; i < MAXN; ++i ){
        dp[1][i] = i;
    }
    for(int r = 2; r < MAXN; ++r) {
        for (int c = r; c < MAXN; ++c) {
            // 오른쪽에 새로운 노드가 추가되면 그 노드랑 연결 안한 경우의 수는 dp[r][c-1]
            // 새로추가 된 노드랑 연결했을 때 경우의 수는 dp[r-1][c-1]
            dp[r][c] = dp[r][c-1] + dp[r-1][c-1];
        }
    }

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        cout << dp[n][m] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}