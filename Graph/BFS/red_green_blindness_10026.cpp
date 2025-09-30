// Problem: BOJ 10026

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<string> graph;
vector<vector<int>> v1;
vector<vector<int>> v2;
int n;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int bfs1(int r, int c) {
    if (v1[r][c]) return 0;
    queue<pii> q;
    q.push({r, c});
    v1[r][c] = 1;
    while(!q.empty()) {
        auto [cur_r, cur_c] = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = cur_r + dr[i];
            int nc = cur_c + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if (!v1[nr][nc] && graph[nr][nc] == graph[cur_r][cur_c]) {
                q.push({nr, nc});
                v1[nr][nc] = 1;
            }
        }
    }
    return 1;
}

int bfs2(int r, int c) {
    if (v2[r][c]) return 0;
    queue<pii> q;
    q.push({r, c});
    v2[r][c] = 1;
    while(!q.empty()) {
        auto [cur_r, cur_c] = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = cur_r + dr[i];
            int nc = cur_c + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if (!v2[nr][nc]) {
                // 파란색이면 같을 때만
                if (graph[cur_r][cur_c] == 'B') {
                    if (graph[nr][nc] == graph[cur_r][cur_c]) {
                        q.push({nr, nc});
                        v2[nr][nc] = 1;
                    }
                } 
                // 파란색이 아닌 색들은 파란색이 아니면 이어주기
                else {
                    if (graph[nr][nc] == 'G' || graph[nr][nc] == 'R') {
                        q.push({nr, nc});
                        v2[nr][nc] = 1;
                    }
                }
                
            }
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    n; cin >> n;
    graph = vector<string>(n);
    v1.assign(n, vector<int>(n, 0));
    v2.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i ++) cin >> graph[i];
    int ans1 = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            ans1 += bfs1(i, j);
        }
    }
    int ans2 = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            ans2 += bfs2(i, j);
        }
    }

    cout << ans1 << " " << ans2 << endl;
    return 0;
}