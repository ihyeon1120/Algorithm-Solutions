// Problem: BOJ 2316

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
const int split = 400;
const int inf = INT_MAX;

struct Edge {
    int to, cap, rev;
};
// 정점 분할을 위해 2배로 만듬 ex) 3번 노드를 3과 403으로 바꾸기
vector<Edge> adj[2*MAXN];
vector<int> parent;
vector<int> parent_edge_idx;

void add_edge(int s, int e, int w) {
    adj[s].push_back({e, w, sz(adj[e])});
    adj[e].push_back({s, 0, sz(adj[s]) - 1});
}

int max_flow(int source, int sink) {
    int total = 0;
    while(1) {
        parent.assign(2*MAXN, -1);
        parent_edge_idx.assign(2*MAXN, -1);
        queue<int> q;
        q.push(source);
        while(!q.empty()) {
            int here = q.front(); q.pop();
            for (int i = 0; i < sz(adj[here]); ++i) {
                Edge &e = adj[here][i];
                if (e.cap > 0 && parent[e.to] == -1) {
                    parent[e.to] = here;
                    parent_edge_idx[e.to] = i;
                    q.push(e.to);
                } 
            }
        }

        if (parent[sink] == -1) break;

        int amount = inf;
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
    int source = 1;
    int sink = 2;
    // 정점 분할
    for (int node = 3; node < n + 1; ++node) {
        add_edge(node, node + split, 1);
    }

    add_edge(source, source + split, inf);
    add_edge(sink, sink + split, inf);

    while(p--) {
        int u, v; cin >> u >> v;
        // 양방향 간선
        int u_out = u + split;
        int v_out = v + split;

        add_edge(u_out, v, 1);
        add_edge(v_out, u, 1);

    }
    cout << max_flow(source + split, sink) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}