// Problem: J

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
    int N, M, K, S, T; cin >> N >> M >> K >> S >> T;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<vector<vector<ll>>> adj(N+1);
    vector<ll> dist(N+1, LONG_LONG_MAX);
    while(M--) {
        ll u, v, c, p; cin >> u >> v >> c >> p;
        adj[u].push_back({c, v, p});
    }
    pq.push({0, S});
    while(!pq.empty()) {
        auto [cur_time, cur_node] = pq.top(); pq.pop();
        if (dist[cur_node] < cur_time) continue;
        for (vector<ll> nxt : adj[cur_node]) {
            ll cost = nxt[0]; ll next_node = nxt[1]; ll p = nxt[2];
            if (cur_time % p != 0) continue;
            ll total_time = cur_time + cost;
            if (dist[next_node] > total_time) {
                pq.push({total_time, next_node});
                dist[next_node] = total_time;
            }
        }
    }

    cout << ((dist[T] == LONG_LONG_MAX) ? -1 : dist[T]) << endl;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}