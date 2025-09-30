// Problem: BOJ 7562

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<vector<int>> visited;
int dr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dc[8] = {2, 1, -1, -2, 2, 1, -1, -2};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int sr, sc; cin >> sr >> sc;
        int er, ec; cin >> er >> ec;
        visited = vector<vector<int>>(n, vector<int>(n, 0));
        queue<pii> q;
        q.push({sr, sc});
        visited[sr][sc] = 1;
        while(!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int i = 0; i < 8; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if (visited[nr][nc] == 0) {
                    q.push({nr, nc});
                    visited[nr][nc] = visited[r][c] + 1;
                }
            }
        }
        cout << visited[er][ec] - 1 << endl;
    }

    return 0;
}