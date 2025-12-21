#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rin for (int i = 0; i < n; ++i)
#define riN for (int i = 0; i < N; ++i)
#define rjn for (int j = 0; j < n; ++j)
#define rjN for (int j = 0; j < N; ++j)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100001;
int N;
int people[MAXN];
int v[MAXN];
int dp[MAXN][2];
vector<int> adj[MAXN];

void dfs(int node) {
    v[node] = 1;
    dp[node][0] = 0;
    dp[node][1] = people[node];

    for (int next : adj[node]) {
        if (v[next] != 0) continue;
        dfs(next);
        dp[node][1] += dp[next][0];
        dp[node][0] += max(dp[next][0], dp[next][1]);
    }
}

void solve() {
    cin >> N;
    riN cin >> people[i+1];
    N--;
    riN {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}