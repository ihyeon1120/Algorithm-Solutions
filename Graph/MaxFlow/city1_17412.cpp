// Problem: BOJ 17412

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 401;
const int INF = INT_MAX;

struct Edge {
    int to, cap, rev;
};

vector<Edge> adj[MAXN];
vector<int> parent;
vector<int> parent_edge_idx;


void add_edge(int s, int e, int w) {
    adj[s].push_back({e, w, sz(adj[e])});
    adj[e].push_back({s, 0, sz(adj[s]) - 1});
}

int max_flow(int source, int sink) {
    int total = 0;
    while(1) {
        parent.assign(MAXN, -1);
        parent_edge_idx.assign(MAXN, -1);
        queue<int> q;
        q.push(source);
        while(!q.empty()) {
            int here = q.front(); q.pop();
            for (int i = 0; i < sz(adj[here]); ++i) {
                Edge &e = adj[here][i];
                // 잔여 용량이 0보다 크고 목적지의 방문여부 체크 (BFS)
                if (e.cap > 0 && parent[e.to] == -1) {
                    parent[e.to] = here;
                    parent_edge_idx[e.to] = i;
                    q.push(e.to);
                }
            }
        }

        if (parent[sink] == -1) break;

        int amount = INF;
        // 경로 중에 최소 용량을 찾음
        for (int p = sink; p != source; p = parent[p]) {
            int prev = parent[p];
            int edge_idx = parent_edge_idx[p];
            amount = min(amount, adj[prev][edge_idx].cap);
        }

        for (int p = sink; p != source; p = parent[p]) {
            int prev = parent[p];
            int edge_idx = parent_edge_idx[p];

            adj[prev][edge_idx].cap -= amount;
            int rev_edge_idx = adj[prev][edge_idx].rev;
            adj[p][rev_edge_idx].cap += amount;
        }

        total += amount;
    }

    return total;
}

void solve() {
    int n, p; cin >> n >> p;
    while(p--) {
        int u, v; cin >> u >> v;
        add_edge(u, v, 1);
    }

    cout << max_flow(1, 2) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}