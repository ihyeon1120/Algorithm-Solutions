// Problem: BOJ 1953

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
        else if (color[nxt] == 0) dfs(nxt, -c);
    }
}


void solve() {
    int n; cin >> n;
    adj = vector<vector<int>>(n+1);
    for (int i = 1; i <= n; ++i) {
        int k; cin >> k;
        while (k--) {
            int t; cin >> t;
            adj[i].push_back(t);
            adj[t].push_back(i);
        }
    }
    color = vector<int>(n+1, 0);
    is_bipartite = true;
    for (int i = 1; i <= n; ++i) {
        if(color[i] == 0) 
            dfs(i, 1);
        
    }
    vector<int> team1, team2;
    for (int i = 1; i <= n; ++i) {
        if(color[i] == 1) team1.push_back(i);
        else team2.push_back(i);
    }
    cout << sz(team1) << endl;
    for (int x : team1) cout << x << " ";
    cout << endl;

    cout << sz(team2) << endl;
    for (int x : team2) cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}