// Problem: BOJ 11400

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
vector<vector<int>> adj;
vector<int> discovered;
int vertex_cnt = 0;
set<pii> edges;

int dfs(int cur, int parent) {
    int low = discovered[cur] = vertex_cnt++;

    for (int next : adj[cur]) {
        if (next == parent) continue;
        if (discovered[next] == -1) {
            int subtree = dfs(next, cur);
            if (subtree > discovered[cur]) {
                if (cur <= next) edges.insert({cur, next});
                else edges.insert({next, cur});
            }
            low = min(low, subtree);
        } 
        else {
            low = min(low, discovered[next]);
        }
    }

    return low;

}

void solve() {
    adj.assign(MAXN, vector<int>());
    discovered.assign(MAXN, -1);

    int v, e; cin >> v >> e;
    
    while(e--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    } 

    for (int i = 1; i < v+1; i++)
        if (discovered[i] == -1) dfs(i, 0);
    
    cout << edges.size() << endl;
    for (pii i : edges) {
        cout << i.first << " " << i.second << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}