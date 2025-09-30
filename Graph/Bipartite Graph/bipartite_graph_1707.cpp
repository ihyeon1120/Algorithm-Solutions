// Problem: BOJ 1707

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
vector<int> visited;

bool is_bipartite(int node, int color) {
    visited[node] = color;
    for (int next : adj[node]) {
        if (visited[next] == 0) {
            if (!is_bipartite(next, -color)) {
                return false;
            }
        } 
        else if (visited[next] == visited[node]) return false;
        
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int v, e; cin >> v >> e;
        adj = vector<vector<int>>(v+1);
        while(e--) {
            int s, e; cin >> s >> e;
            adj[s].push_back(e);
            adj[e].push_back(s);
        }
        visited = vector<int>(v+1, 0);
        bool flag = true;
        for (int i = 1; i <= v; ++i) {
            if (visited[i] == 0) { 
                if (!is_bipartite(i, 1)) { 
                    flag = false;
                    break;
                }
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }

    return 0;
}