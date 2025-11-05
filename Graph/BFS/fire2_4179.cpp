#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

typedef pair<int, int> pii;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int r, c;
vector<string> board;
vector<vector<int>> fire_dist; 
vector<vector<int>> jihun_dist; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;
    board.resize(r);
    
    fire_dist.assign(r, vector<int>(c, -1));
    jihun_dist.assign(r, vector<int>(c, -1));

    queue<pii> fq; 
    queue<pii> jq; 

    for (int i = 0; i < r; ++i) {
        cin >> board[i];
        for (int j = 0; j < c; ++j) {
            if (board[i][j] == 'F') {
                fq.push({i, j});
                fire_dist[i][j] = 0;
            } else if (board[i][j] == 'J') {
                jq.push({i, j});
                jihun_dist[i][j] = 0; 
            }
        }
    }

    // 1. 불에 대한 BFS 먼저 실행
    while (!fq.empty()) {
        auto [cur_r, cur_c] = fq.front(); fq.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = cur_r + dr[i];
            int nc = cur_c + dc[i];
            if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
            if (board[nr][nc] == '#' || fire_dist[nr][nc] >= 0) continue;
            fire_dist[nr][nc] = fire_dist[cur_r][cur_c] + 1;
            fq.push({nr, nc});
        }
    }

    // 2. 지훈에 대한 BFS 실행
    while (!jq.empty()) {
        auto [cur_r, cur_c] = jq.front(); jq.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = cur_r + dr[i];
            int nc = cur_c + dc[i];
            
            if (nr < 0 || nr >= r || nc < 0 || nc >= c) {
                cout << jihun_dist[cur_r][cur_c] + 1 << endl;
                return 0;
            }
            
            if (jihun_dist[nr][nc] >= 0 || board[nr][nc] == '#') continue;
            
            // 불이 번지는 시간보다 늦게 도착하면 안됨
            // fire_dist[nr][nc] == -1은 불이 도달하지 못하는 곳
            if (fire_dist[nr][nc] != -1 && jihun_dist[cur_r][cur_c] + 1 >= fire_dist[nr][nc]) {
                continue;
            }
            
            jihun_dist[nr][nc] = jihun_dist[cur_r][cur_c] + 1;
            jq.push({nr, nc});
        }
    }
    
    cout << "IMPOSSIBLE" << endl;

    return 0;
}