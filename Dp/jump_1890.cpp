// Problem: BOJ 1890

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void solve(int n, const vector<vector<int>>& graph) {
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    dp[0][0] = 1;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (dp[r][c] == 0) continue;
            if (r == n - 1 && c == n - 1) continue;

            int jump = graph[r][c];

            int nc = c + jump;
            if (nc < n) dp[r][nc] += dp[r][c];
            
            int nr = r + jump;
            if (nr < n) dp[nr][c] += dp[r][c];
        }
    }
    cout << dp[n-1][n-1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<vector<int>> graph(n, (vector<int>(n)));
    for(int i = 0; i<n; i++) {
        for(int j = 0; j < n; j++) cin >> graph[i][j];
    }
    solve(n, graph);

    return 0;
}