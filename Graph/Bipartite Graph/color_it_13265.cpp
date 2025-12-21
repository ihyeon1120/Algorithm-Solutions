// Problem: BOJ 13265

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<vector<int>> adj;
vector<int> color;
bool is_bipartite;

void dfs(int node, int c) {
    color[node] = c;
    for (int nxt : adj[node]) {
        if (color[nxt] == color[node]) is_bipartite = false;
        else if (color[nxt] == 0) {
            dfs(nxt, -c);
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    adj = vector<vector<int>>(n+1);
    while(m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    color = vector<int>(n+1, 0);
    is_bipartite = true;
    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0)
            dfs(i, 1);
    }
    string ans = (is_bipartite) ? "possible" : "impossible";
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc;
    while(tc--)
        solve();

    return 0;
}