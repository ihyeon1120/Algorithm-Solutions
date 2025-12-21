#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<bool> color(n+1, 0); // 0 -> W , 1 -> B

    function<void(int)> dfs = [&](int node) -> void {
        if (color[node] == 1) return;
        color[node] = 1;
        for (int next : adj[node]) {
            if (color[next] == 0) dfs(next); 
        }
    };

    while(m--) {
        int x, y; cin >> x >> y;
        adj[y].push_back(x); // 역방향 간선
    }
    int q; cin >> q;
    while(q--) {
        int t; cin >> t;
        if (t == 1) {
            int v; cin >> v;
            dfs(v);
        }
        else {
            int v; cin >> v;
            cout << (color[v] ? "Yes" : "No") << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}