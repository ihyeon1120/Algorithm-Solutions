// Problem: BOJ 3176

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<vector<pii>> adj;

const int MAXN = 100001;
const int LOGN = (int)ceil(log2(MAXN));

vector<vector<int>> parent(MAXN, vector<int>(LOGN, 0));
vector<int> depth(MAXN, -1);
vector<vector<int>> min_d(MAXN, vector<int>(LOGN, (1<<30)));
vector<vector<int>> max_d(MAXN, vector<int>(LOGN, 0));

void dfs(int cur, int par, int dep, int d) {
    parent[cur][0] = par;
    depth[cur] = dep;

    min_d[cur][0] = d;
    max_d[cur][0] = d;

    for (auto& [next, w] : adj[cur]) {
        if (next == par) continue;
        dfs(next, cur, dep + 1, w);
    }
}

void create_sparse() {
    for (int k = 1; k < LOGN; ++k) {
        for (int i = 1; i < MAXN; ++i) {
            parent[i][k] = parent[parent[i][k-1]][k-1];
            min_d[i][k] = min(min_d[i][k-1], min_d[parent[i][k-1]][k-1]);
            max_d[i][k] = max(max_d[i][k-1], max_d[parent[i][k-1]][k-1]);
        }
    }
}

void lca(int u, int v) {

    int min_res = 1 << 30;
    int max_res = 0;

    if (u == v) {
        cout << "0 0" << endl;
        return;
    }
    
    if (depth[u] < depth[v]) swap(u, v);
    for (int k = LOGN - 1; k >= 0; --k) {
        if (depth[u] - (1 << k) >= depth[v]) {
            min_res = min(min_res, min_d[u][k]);
            max_res = max(max_res, max_d[u][k]);
            u = parent[u][k];
        }
    }

    if (u == v) {
        cout << min_res << " " << max_res << endl;
        return;
    }

    for (int k = LOGN - 1; k >= 0; --k) {
        if (parent[u][k] != parent[v][k]) {
            min_res = min(min_res, min_d[u][k]);
            min_res = min(min_res, min_d[v][k]);
            max_res = max(max_res, max_d[u][k]);
            max_res = max(max_res, max_d[v][k]);
            u = parent[u][k];
            v = parent[v][k];
        }
    }

    min_res = min(min_res, min_d[u][0]);
    min_res = min(min_res, min_d[v][0]);
    max_res = max(max_res, max_d[u][0]);
    max_res = max(max_res, max_d[v][0]);

    cout << min_res << " " << max_res << endl;

    // return parent[u][0];
}

void solve() {
    int n; cin >> n;
    adj.assign(n+1, vector<pii>());

    while(--n) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1, 0, 0, 0);
    create_sparse();

    int m; cin >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        lca(u, v);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();

    return 0;
}