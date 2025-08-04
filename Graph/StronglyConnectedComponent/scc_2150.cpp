// Problem: BOJ 2150

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

vector<vector<int>> adj(MAXN);
vector<int> sccId;
vector<int> discovered;
stack<int> s;
int sccCounter, vertexCounter;
vector<vector<int>> result(MAXN);

bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

int scc(int here) {
    int ret = discovered[here] = vertexCounter++;
    s.push(here);
    for(int i = 0; i < (int)adj[here].size(); ++i) {
        int there = adj[here][i];
        if (discovered[there] == -1) 
            ret = min(ret, scc(there));
        else if (sccId[there] == -1) 
            ret = min(ret, discovered[there]);
    }
    // here에서 부모로 가는 간선을 끊을지 확인
    if (ret == discovered[here]) {
        while (1)
        {
            int t = s.top(); s.pop();
            sccId[t] = sccCounter;
            result[sccCounter].push_back(t);
            if(t == here) break;
        }
        sort(all(result[sccCounter]));
        ++sccCounter;
    }
    return ret;

}

void solve() {
    sccId.assign(MAXN, -1);
    discovered.assign(MAXN, -1);
    sccCounter = vertexCounter = 0;
    int v, e; cin >> v >> e;
    while (e--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i = 1; i < v+1; ++i) {
        if(discovered[i] == -1) scc(i);
    }

    sort(result.begin(), result.begin() + sccCounter, cmp);

    cout << sccCounter << endl;
    for (int i = 0; i < sccCounter; ++i) {
        for(int j = 0; j < (int)result[i].size(); ++j) {
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