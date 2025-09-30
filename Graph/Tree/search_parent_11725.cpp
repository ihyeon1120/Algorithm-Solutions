// Problem: BOJ 11725

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> parent;
vector<vector<int>> adj;
void dfs(int node, int p) {
    parent[node] = p;
    for (int next : adj[node]) {
        if (next == p) continue;
        dfs(next, node);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int c = n;
    adj = vector<vector<int>>(n+1);
    parent.assign(n+1, -1);
    while(--c) {
        int s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    dfs(1, 0);
    for (int i = 2; i < n+1; ++i) cout << parent[i] << endl;
    return 0;
}