// Problem: BOJ 4196

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
vector<int> discovered;
vector<int> sccID;
int vertex, sccCounter;
vector<int> indegree;

vector<vector<int>> adj;
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

void solve() {
    int t; cin >> t;

    while (t--)
    {
        adj.assign(MAXN, vector<int>());
        discovered.assign(MAXN, -1);
        sccID.assign(MAXN, -1);
        vertex = sccCounter = 0;
        while(!s.empty()) s.pop();

        int n, m; cin >> n >> m;
        while (m--)
        {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
        }
        // scc를 통해 DAG을 생성
        for(int i = 1; i < n+1; ++i) {
            if(discovered[i] == -1) scc(i);
        }

        // scc통해 생성된 DAG을 통해서 위상정렬의 indegree 방식을 채용하여 진입 차수가 0인 것들만 뽑아내기
        indegree.assign(sccCounter, 0);
        for (int u = 1; u < n + 1; u++) {
            for(int v : adj[u]) {
                if (sccID[u] != sccID[v]) indegree[sccID[v]]++;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < sccCounter; i++)
        {
            if (indegree[i] == 0) ans++;
        }
        
        cout << ans << endl;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}