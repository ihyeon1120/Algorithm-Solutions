// Problem: BOJ 18352

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, x; cin >> n >> m >> k >> x;
    vector<vector<int>> ans(k + 1);
    vector<vector<int>> adj(n + 1);
    vector<int> v(n + 1, -1);
    int dist = 0;
    while(m--) {
        int s, e; cin >> s >> e;
        adj[s].push_back(e);
    }

    queue<int> q;
    q.push(x);
    v[x] = 0;
    ans[v[x]].push_back(x);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for (int next : adj[cur]) {
            if (v[next] != -1) continue;
            q.push(next);
            v[next] = v[cur] + 1;
            if (v[next] <= k) 
                ans[v[next]].push_back(next);
        }
    }
    if (sz(ans[k]) == 0) {
        cout << -1;
        return 0;
    }
    sort(all(ans[k]));
    for (int i : ans[k])
        cout << i << endl;
    return 0;
}