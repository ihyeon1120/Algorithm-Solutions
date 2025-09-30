// Problem: BOJ 4963

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
vector<vector<int>> visited;
int mr, mc;

int dr[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dc[8] = {1, 0, -1, 1, 0, -1, 1, -1};

int bfs(int r, int c) {
    if (graph[r][c] == 0 || visited[r][c]) return 0;
    queue<pii> q;
    q.push({r, c});
    visited[r][c] = 1;
    while(!q.empty()) {
        auto [cr, cc] = q.front(); q.pop();
        for (int i = 0; i < 8; ++i) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr < 0 || nr >= mr || nc < 0 || nc >= mc) continue;
            if (!visited[nr][nc] && graph[nr][nc] == 1) {
                q.push({nr, nc});
                visited[nr][nc] = 1;
            }
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        mc, mr; cin >> mc >> mr;
        if (mc == 0 && mr == 0) break;
        graph = vector<vector<int>>(mr, vector<int>(mc, -1));
        visited = vector<vector<int>>(mr, vector<int>(mc, 0));
        for (int i = 0; i < mr; ++i)
            for (int j = 0; j < mc; ++j)
                cin >> graph[i][j];
        int ans = 0;
        for (int i = 0; i < mr; ++i)
            for (int j = 0; j < mc; ++j)
                ans += bfs(i, j);
        cout << ans << endl;
    }

    return 0;
}