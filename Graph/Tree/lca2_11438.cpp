// Problem: BOJ 11438

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100001;
const int LOGN = (int)ceil(log2(MAXN));

vector<vector<int>> adj;
vector<int> depth;
vector<vector<int>> parent;

void dfs(int cur, int par, int dep) {
    depth[cur] = dep;
    parent[cur][0] = par;
    for (int next : adj[cur]) {
        if (next == par) continue;
        dfs(next, cur, dep+1);
    }
}

void create_sparse() {
    for (int k = 1; k < LOGN; k++) {
        for (int i = 1; i < MAXN; i++) {
            parent[i][k] = parent[parent[i][k-1]][k-1];
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int k = LOGN - 1; k >= 0; k--) {
        if (depth[u] - (1 << k) >= depth[v]) 
            u = parent[u][k];
    }

    if (u == v) return u;

    for (int k = LOGN - 1; k >= 0; k--) {
        if (parent[u][k] != parent[v][k]) {
            u = parent[u][k];
            v = parent[v][k];
        }
    }

    return parent[u][0];
}

void solve() {
    int n; cin >> n;
    n--;
    while (n--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, 0);
    create_sparse();
    int m; cin >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        cout << lca(u, v) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    adj.assign(MAXN, vector<int>());
    depth.assign(MAXN, -1);
    parent.assign(MAXN, vector<int>(LOGN, 0));

    solve();

    return 0;
}