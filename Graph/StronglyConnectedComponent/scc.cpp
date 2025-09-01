// Problem: BOJ 

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

vector<vector<int>> adj;
vector<int> discovered;
vector<int> sccID;
vector<int> lowlink;
stack<int> s;
vector<vector<int>> result(MAXN);

int sccCounter, vertexCounter;

bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

int scc(int cur) {
    discovered[cur] = vertexCounter++;
    int lowlink = discovered[cur];
    s.push(cur);
    
    for(int next : adj[cur]) {
        // 아직 방문하지 않은 곳
        if (discovered[next] == -1) {
            lowlink = min(lowlink, scc(next));
        }
        /*
            방문은 했지만 scc가 포함되지 않은 곳
            next -> ... -> cur -> next인 상황 (역방향 간선)
            lowlink에 왜 scc(next)로 갱신하지 않고 discovered로 갱신하는 이유
            최소한 next가 발견된 순서가 lowlink이기 때문에
        */
        else if (sccID[next] == -1) {
            lowlink = min(lowlink, discovered[next]);
        }
    }
    if (discovered[cur] == lowlink) {
        while (1)
        {
            int temp = s.top(); s.pop();
            sccID[temp] = sccCounter;
            result[sccCounter].push_back(temp);
            if(cur == temp) break;
        }
        sort(all(result[sccCounter]));
        ++sccCounter;
    }
    return lowlink;
}

void solve() {
    int v, e; cin >> v >> e;

    adj.assign(v+1, vector<int>());
    discovered.assign(MAXN, -1);
    sccID.assign(MAXN, -1);
    lowlink.assign(MAXN, -1);
    sccCounter = vertexCounter = 0;

    while (e--)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    
    for (int i = 1; i < v+1; ++i) {
        if(discovered[i] == -1) scc(i);
    }

    sort(result.begin(), result.begin() + sccCounter, cmp);
    cout << sccCounter << endl;
    for (int i = 0; i < sccCounter; i++)
    {
        for (int j = 0; j < (int)result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << -1 << endl;
        
    }
    
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}