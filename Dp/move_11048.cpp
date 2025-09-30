// Problem: BOJ 11048

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<pii> dir = {{-1, 0}, {0, -1}, {-1, -1}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j)
            cin >> graph[i][j];
    dp[0][0] = graph[0][0];
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            for (auto [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr < 0 || nc < 0) continue;
                dp[r][c] = max(dp[r][c], dp[nr][nc] + graph[r][c]);
            }
        }
    }
    cout << dp[n-1][m-1];
    return 0;
}