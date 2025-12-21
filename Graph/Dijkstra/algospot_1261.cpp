// Problem: BOJ 1261

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {

    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    int c, r; cin >> c >> r;
    vector<vector<int>> graph(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
        string s; cin >> s;
        for (int j = 0; j < c; ++j) {
            graph[i][j] = s[j] - '0';
        }
    }
    vector<vector<int>> dist(r, vector<int>(c, INT32_MAX));
    dist[0][0] = 0;
    queue<pii> q;
    q.push({0, 0});
    while(!q.empty()) {
        auto [cur_r, cur_c] = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = cur_r + dr[i];
            int nc = cur_c + dc[i];
            if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
            if (dist[cur_r][cur_c] + graph[nr][nc] < dist[nr][nc]) {
                q.push({nr, nc});
                dist[nr][nc] = dist[cur_r][cur_c] + graph[nr][nc];
            }
        }
    }
    
    cout << dist[r-1][c-1] << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}