// Problem: BOJ 14938

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
    int n, m, r; cin >> n >> m >> r;
    vector<int> items(n + 1, 0);
    for (int i = 0; i < n; ++ i) cin >> items[i+1];
    vector<vector<pii>> adj(n+1);
    for (int i = 0; i < r; ++i) {
        int a, b, l; cin >> a >> b >> l;
        adj[a].push_back({l, b});
        adj[b].push_back({l, a});
    }

    function<int(int)> dijkstra = [&](int node) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(n+1, INT32_MAX);

        dist[node] = 0;
        pq.push({0, node});
        while (!pq.empty()) {
            auto [cur_cost, cur_node] = pq.top(); pq.pop();
            if (dist[cur_node] < cur_cost) continue;
            for (auto [cost, next] : adj[cur_node]) {
                int total_cost = cur_cost + cost;
                if (total_cost < dist[next] && total_cost <= m) {
                    dist[next] = total_cost;
                    pq.push({total_cost, next});
                }
            }
        }
        int ret = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] <= m) ret += items[i];
        }
        return ret;
    };

    int ans = 0;
    for (int i = 1; i < n+1; ++i) {
        ans = max(ans, dijkstra(i));
    }

    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}