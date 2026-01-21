// Problem: BOJ 13511

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#ifndef ONLINE_JUDGE
template<typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
    return os << "{" << p.first << ", " << p.second << "}";
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1) os << ", ";
    }
    return os << "]";
}

#define debug(...) cerr << "[DEBUG] " << #__VA_ARGS__ << ": ", DBG(__VA_ARGS__)
template<typename T> void DBG(const T& v) { cerr << v << endl; }
template<typename T, typename... Args> void DBG(const T& v, const Args&... args) { cerr << v << ", "; DBG(args...); }
#else
#define debug(...)
#endif

vector<vector<int>> parent;
vector<ll> dist;
vector<vector<pll>> adj;
vector<int> depth;
const int MAXN = 32;
int n;

void dfs(int node, ll c, int p, int d) {
    depth[node] = d;
    parent[0][node] = p;
    dist[node] = c;
    for (auto [next, w] : adj[node]) {
        if (next == p) continue;
        dfs(next, c + w, node, d+1);
    }
}

void create_table() {
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 1; j <= n; ++j) {
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; i < MAXN; ++i) {
        if ((diff >> i) & 1) {
            u = parent[i][u];
        }
    }
    if (u == v) return u;
    
    for (int i = MAXN - 1; i >= 0; --i) {
        if (parent[i][u] != parent[i][v]) {
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][u];
}

int get_ancestor(int u, int k) {
    for (int i = 0; i < MAXN; ++i) {
        if ((k >> i) & 1) {
            u = parent[i][u];
        }
    }
    return u;
}

void solve() {
    cin >> n;
    adj.resize(n+1);
    parent.resize(MAXN, vector<int>(n+1, 0));
    dist.resize(n+1);
    depth.resize(n+1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1, 0, 0, 0);
    create_table();
    for (int i = 0; i < MAXN; ++i) debug(parent[i]);
    int q; cin >> q;
    while(q--) {
        int t; cin >> t;
        int u, v; cin >> u >> v;
        int l = lca(u, v);
        
        if (t == 1) {
            cout << dist[u] + dist[v] - 2*dist[l] << endl;;
        }
        else {
            int ans;
            int k; cin >> k;
            k--;
            int diff = depth[u] - depth[l];
            if (k == diff) ans = l;
            else if (k < diff) ans = get_ancestor(u, k);
            else {
                k -= diff;
                ans = get_ancestor(v, depth[v] - depth[l] - k);
            }
            cout << ans << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}