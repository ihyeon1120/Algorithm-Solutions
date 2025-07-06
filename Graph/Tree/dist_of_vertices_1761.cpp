// Problem: BOJ 1761

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<pii> parent(40001, {0, 0});
vector<bool> visited(40001, false);
vector<int> d(40001, 0);
vector<vector<pii>> graph;

void dfs(int node, int depth) {
    visited[node] = true;
    d[node] = depth;
    for (pii next : graph[node]) {
        auto [next_node, dist] = next;
        if (visited[next_node]) continue;
        parent[next_node] = {node, dist}; 
        dfs(next_node, depth + 1);
    }
}

int lca(int node1, int node2) {
    int ans = 0;
    while (d[node1] != d[node2]) {
        if (d[node1] > d[node2]) {
            ans += parent[node1].second;
            node1 = parent[node1].first;
        }
        else {
            node2 = parent[node2].first;
            ans += parent[node2].second;
        }
    }
    while (node1 != node2) {
        ans += parent[node1].second;
        node1 = parent[node1].first;
        ans += parent[node2].second;
        node2 = parent[node2].first;
    }
    return ans;
}

void solve() {
    int N; cin >> N;
    graph.assign(N+1, vector<pii>());
    N--;
    while (N--) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    dfs(1, 0);
    int M; cin >> M;
    while (M--)
    {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << endl;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    
    return 0;
}