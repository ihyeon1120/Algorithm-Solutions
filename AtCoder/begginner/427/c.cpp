// Problem:  

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
int n, m;
int cut;
void dfs(int node, int c){
    color[node] = c;
    for (int next : adj[node]) {
        if (color[next] == color[node]) {
            cut ++;
        }
        else if (color[next] == 0) {
            dfs(next, -c);
        }
    }
}

void solve() {
    cin >> n >> m;
    adj = vector<vector<int>>(n+1);
    while(m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        color = vector<int>(n+1, 0);
        cut = 0;
        dfs(i, 1);
        ans = min(ans, cut);
    }
    cout << ans / 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}