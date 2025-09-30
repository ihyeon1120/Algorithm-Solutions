// Problem: BOJ 2583

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
vector<vector<int>> v;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int r, c;

int bfs(int s, int e) {
    // 방문 했거나 벽이라면 넘기기
    if (v[s][e] || graph[s][e] == 0) return 0;
    queue<pii> q;
    q.push({s, e});
    v[s][e] = 1;
    int cnt = 1;
    while(!q.empty()) {
        auto [cr, cc] = q.front(); q.pop();
        for (int i = 0; i < 4; i ++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
            if (!v[nr][nc] && graph[nr][nc] == 1) {
                q.push({nr, nc});
                v[nr][nc] = 1;
                cnt ++;
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k; cin >> r >> c >> k;
    graph = vector<vector<int>>(r, vector<int>(c, 1));
    v = vector<vector<int>>(r, vector<int>(c, 0));
    while(k--) {
        int sc, sr, ec, er; cin >> sc >> sr >> ec >> er;    
        for (int r = sr; r < er; ++r) {
            for (int c = sc; c < ec; ++c) {
                graph[r][c] = 0;
            }
        }
    }

    vector<int> arr;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            int t = bfs(i, j);
            if (t != 0) arr.push_back(t); 
        }
    }
    sort(all(arr));
    cout << sz(arr) << endl;
    for (int i : arr) cout << i << " ";
    return 0;
}