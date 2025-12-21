#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 200001;
vector<int> discovered;
vector<int> sccID;
int vertex, sccCounter;
vector<int> indegree;
int ans;

vector<vector<int>> adj;
vector<vector<int>> adj_scc;
vector<int> visited_scc;
stack<int> s;

int scc(int cur) {
    int lowlink = discovered[cur] = vertex++;
    s.push(cur);

    for (int next : adj[cur]) {
        if (discovered[next] == -1) lowlink = min(lowlink, scc(next));
        else if (sccID[next] == -1) lowlink = min(lowlink, discovered[next]);
    }

    if (lowlink == discovered[cur]) {
        while (1){
            int temp = s.top(); s.pop();
            sccID[temp] = sccCounter;
            if (temp == cur) break;
        }
        sccCounter++;
    }
    return lowlink;
}

void dfs(int node) {
    for (int next : adj_scc[node]) {
        if (!visited_scc[next]) { 
            visited_scc[next] = 1; 
            ans++; 
            dfs(next);
        }
    }
}

void solve() {
    adj.assign(MAXN, vector<int>());
    discovered.assign(MAXN, -1);
    sccID.assign(MAXN, -1);
    vertex = sccCounter = 0;

    int n, m, x; cin >> n >> m >> x;
    while (m--)
    {
        int x, y; cin >> x >> y;
        adj[y].push_back(x);
    }
    // scc를 통해 DAG을 생성
    for(int i = 1; i < n+1; ++i) {
        if(discovered[i] == -1) scc(i);
    }

    adj_scc = vector<vector<int>>(sccCounter+1);
    visited_scc = vector<int>(sccCounter+1, 0);
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (sccID[u] != sccID[v]) {
                adj_scc[sccID[v]].push_back(sccID[u]);
            }
        }
    }
    
    ans = 0;
    dfs(sccID[x]);
    cout << sccCounter - ans - 1 << endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}