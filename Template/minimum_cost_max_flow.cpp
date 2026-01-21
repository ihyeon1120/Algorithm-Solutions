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

#ifndef ONLINE_JUDGE
template<typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
    return os << "{" << p.first << ", " << p.second << "}";
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1) os << ", ";
    }
    return os << "]";
}

#define debug(...) cerr << "[DEBUG] " << #__VA_ARGS__ << ": ", DBG(__VA_ARGS__)
template<typename T> void DBG(const T& v) { cerr << v << endl; }
template<typename T, typename... Args> void DBG(const T& v, const Args&... args) { cerr << v << ", "; DBG(args...); }
#else
#define debug(...)
#endif

struct Edge {
    int to, capacity, flow, cost, rev;
};

vector<vector<Edge>> adj;
vector<int> dist;
vector<bool> in_queue;
vector<int> parent_node;
vector<int> parent_edge;

void add_edge(int from, int to, int cap, int cost) {
    adj[from].push_back({to, cap, 0, cost, sz(adj[to])});
    adj[to].push_back({from, 0, 0, -cost, sz(adj[from]) - 1});
}

pii mcmf(int source, int sink) {
    int total_flow = 0;
    int total_cost = 0;
    while(1) {
        fill(all(dist), 1e9);
        fill(all(in_queue), false);
        fill(all(parent_node), -1);
        fill(all(parent_edge), -1);

        queue<int> q;
        q.push(source);
        dist[source] = 0;
        in_queue[source] = true;
        while(!q.empty()) {
            int curr = q.front(); q.pop();
            in_queue[curr] = false;
            for (int i = 0; i < sz(adj[curr]); ++i) {
                Edge &e = adj[curr][i];
                if (e.capacity - e.flow > 0 && dist[e.to] > dist[curr] + e.cost) {
                    dist[e.to] = dist[curr] + e.cost;
                    parent_node[e.to] = curr;
                    parent_edge[e.to] = i;
                    if (!in_queue[e.to]) {
                        q.push(e.to);
                        in_queue[e.to] = true;
                    }
                }
            }
        }
        if (parent_node[sink] == -1) break;
        int flow = 1e9;
        for (int v = sink; v != source; v = parent_node[v]) {
            int u = parent_node[v];
            int idx = parent_edge[v];
            flow = min(flow, adj[u][idx].capacity - adj[u][idx].flow);
        }

        for (int v = sink; v != source; v = parent_node[v]) {
            int u = parent_node[v];
            int idx = parent_edge[v];
            int rev_idx = adj[u][idx].rev;

            adj[u][idx].flow += flow;
            adj[v][rev_idx].flow -= flow;
            total_cost += flow * adj[u][idx].cost;
        }
        total_flow += flow;
    }
    return {total_flow, total_cost};
}

void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}