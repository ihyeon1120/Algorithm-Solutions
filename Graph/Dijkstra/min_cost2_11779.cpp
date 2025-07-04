// Problem: BOJ 11779

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

    int N, M; cin >> N >> M;
    vector<vector<pii>> adj(N+1);
    priority_queue<pii, vector<pii>,greater<pii>> pq;

    while (M--){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    int s, e; cin >> s >> e;

    vector<int> dist(N+1, 1e9);
    dist[s] = 0;
    pq.push({0, s});

    vector<int> prev(N+1, 0);

    while (!pq.empty()) {
        pii cur = pq.top(); pq.pop();
        int cur_cost = cur.first;
        int cur_node = cur.second;
        if (dist[cur_node] < cur_cost) continue;
        for (pii next : adj[cur_node]) {
            int total_cost = cur_cost + next.first;
            if (dist[next.second] > total_cost) {
                pq.push({total_cost, next.second});
                dist[next.second] = total_cost;
                prev[next.second] = cur_node;
            }
        }
    }

    vector<int> path;
    int current = e;
    while (current != 0)
    {
        path.push_back(current);
        current = prev[current];
    }
    // 끝점에서 path를 저정해왔으니까 역순
    reverse(all(path));

    cout << dist[e] << endl;
    cout << sz(path) << endl;
    for (int node : path) cout << node << " ";
    return 0;
}