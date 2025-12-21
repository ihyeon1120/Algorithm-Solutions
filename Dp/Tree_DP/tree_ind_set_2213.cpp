// Problem: BOJ 2213

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 10001;
int weight[MAXN];
vector<int> adj[MAXN];
int N;
int dp[MAXN][2];
vector<int> ans;
void dfs(int node, int parent) {
    dp[node][0] = 0;
    dp[node][1] = weight[node];

    for (int next : adj[node]) {
        if (next == parent) continue;
        dfs(next, node);
        dp[node][1] += dp[next][0];
        dp[node][0] += max(dp[next][0], dp[next][1]);
    }
}

void backtraking(int node, int parent, int selected) {
    if (selected == 1) {
        for (int next : adj[node]) {
            if (next == parent) continue;
            backtraking(next, node, 0);
        }
    }
    else {
        if (dp[node][1] > dp[node][0]) {
            ans.push_back(node);
            for (int next : adj[node]) {
                if (next == parent) continue;
                backtraking(next, node, 1);
            }
        }
        else {
            for (int next : adj[node]) {
                if (next == parent) continue;
                backtraking(next, node, 0);
            }
        }
    }
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> weight[i];
    for (int i = 0; i < N-1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    backtraking(1, 0, 0);
    cout << max(dp[1][0], dp[1][1]) << endl;
    sort(all(ans));
    for (int i : ans) cout << i << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}