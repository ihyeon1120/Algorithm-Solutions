// Problem: BOJ 14267

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
vector<int> adj[MAXN];
int ans[MAXN];
int weight[MAXN];

void dfs(int node) {
    if (node == 0) return;
    ans[node] += weight[node];
    for (int next : adj[node]) {
        weight[next] += weight[node];
        dfs(next);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int t; cin >> t;
        if (t == -1) continue;
        adj[t].push_back(i); // t -> i
    }
    while(m--) {
        int i, w; cin >> i >> w;
        weight[i] += w;
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
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