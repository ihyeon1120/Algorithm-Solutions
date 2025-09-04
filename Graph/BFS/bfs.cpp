// Problem: BOJ 

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> visited;
vector<vector<int>> adj;

void bfs(int node) {
    queue<int> q;
    q.push(node);
    int step = 1;
    visited[node] = step++;
    while(!q.empty()){
        int cur = q.back(); q.pop();
        for (int next : adj[cur]) {
            if (visited[next] == 0) {
                q.push(next);
                visited[next] = step++;
            }
        }
    }
}

void solve() {
    int n, m, s; cin >> n >> m >> s;
    adj.assign(n+1, vector<int>());
    visited.assign(n+1, 0);
    while(m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(s);
    for (int i = 1; i <= n; i++) cout << visited[i] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}