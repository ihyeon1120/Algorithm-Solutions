// Problem: BOJ 3584

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define MAX_SIZE 10001

vector<vector<int>> adj;
vector<int> parent;
vector<int> level;

void dfs(int node, int depth) {
    level[node] = depth;
    for (int next : adj[node]) {
        if(parent[next] != 0) continue;
        parent[next] = node;
        dfs(next, depth + 1);
    }
}

void init() {
    int n; cin >> n;
    adj.assign(n+1, vector<int>());
    parent.assign(n+1, 0);
    level.assign(n+1, 0);
    vector<bool> is_root(n+1, true);
    int root;

    for(int i = 0; i < n-1; i++) {
        int s, e; cin >> s >> e;
        adj[s].push_back(e);
        is_root[e] = false;
    }
    for(int i = 1; i < n+1; i++) {
        if(is_root[i]) root = i;
    }
    parent[root] = root;
    dfs(root, 0);

}

int lca(int a, int b) {
    if (level[a] < level[b]) swap(a, b);
    while (level[a] != level[b]) a = parent[a];
    while (a != b)
    {
        a = parent[a];
        b = parent[b];
    }

    return a; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        init();
        int a, b; cin >> a >> b;
        cout << lca(a, b) << endl;
    }

    return 0;
}