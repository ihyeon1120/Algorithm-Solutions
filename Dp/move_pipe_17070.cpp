// Problem: BOJ 2565

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<vector<int>> graph;
vector<vector<vector<int>>> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    graph = vector<vector<int>>(n, vector<int>(n));
    /*
        n * n * 3크기의 3차원 dp 배열 생성
        0 -> 가로
        1 -> 세로
        2 -> 대각선
    */ 
    dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(3, 0)));
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j)
            cin >> graph[i][j];

    dp[0][1][0] = 1;
    for (int r = 0; r < n; ++r) {
        for (int c = 2; c < n; ++c) {
            // 해당 칸이 벽이라면 넘어가기
            if (graph[r][c] == 1) continue;
            // (r, c)에서 가로로 되어있을 경우의 수는 (r, c-1)에서 가로로 되어있는 경우의 수 + 대각선으로 되어있는 경우
            if (c - 1 >= 0) {
                dp[r][c][0] = dp[r][c-1][0] + dp[r][c-1][2];
            }
            if (r - 1 >= 0) {
                dp[r][c][1] = dp[r-1][c][1] + dp[r-1][c][2];
            }
            if (c - 1 >= 0 && r - 1 >= 0) {
                if (graph[r-1][c] == 1 || graph[r][c-1] == 1) continue;
                dp[r][c][2] = dp[r-1][c-1][2] + dp[r-1][c-1][1] + dp[r-1][c-1][0];
            }
        }
    }
    cout << dp[n-1][n-1][0] + dp[n-1][n-1][1] + dp[n-1][n-1][2] << endl;
    return 0;
}