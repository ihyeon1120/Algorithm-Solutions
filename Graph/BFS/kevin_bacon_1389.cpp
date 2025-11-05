// Problem: BOJ 1389

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 케빈-베이컨을 구하려면 각 정점에서 다른 모든 정점의 최소 거리를 구해야함 -> 플로이드 워셜 -> 약 100만회
    // 또는 각 정점에서 bfs를 1번씩 돌려서 풀기 -> O(N(N+M)) -> 약 51만회
    // n <= 100, M <= 5000
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    while(m--) {
        int s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    vector<vector<int>> v(n+1, vector<int>(n+1, -1));
    for (int i = 1; i < n + 1; ++i) {
        queue<int> q;
        q.push(i);
        v[i][i] = 1;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for (int next : adj[cur]) {
                if (v[i][next] != -1) continue;
                q.push(next);
                v[i][next] = v[i][cur] + 1;
            }
        }
    }
    int ans_idx = 0;
    int ans = (1<<30);
    for (int i = 1; i < n + 1; ++i) {
        int sum = 0;
        for (int j = 1; j < n+1; ++j) {
            sum += v[i][j];
        }
        if (sum < ans) {
            ans = sum;
            ans_idx = i;
        }
    }
    cout << ans_idx;

    return 0;
}