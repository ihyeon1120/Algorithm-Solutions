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
    int to, capacity, flow, rev;
};

vector<vector<Edge>> adj;
vector<int> parent_node;
vector<int> parent_edge;

void add_edge(int from, int to, int cap) {
    adj[from].push_back({to, cap, 0, sz(adj[to])});
    adj[to].push_back({from, 0, 0, sz(adj[from]) - 1});
}

int max_flow(int source, int sink) {
    int total_flow = 0;
    while(1) {
        fill(all(parent_node), -1);
        fill(all(parent_edge), -1);
        queue<int> q;
        q.push(source);
        // 증가 경로를 BFS로 찾기
        while(!q.empty() && parent_node[sink] == -1) {
            int curr = q.front(); q.pop();
            for (int i = 0; i < sz(adj[curr]); ++i) {
                Edge &e = adj[curr][i];
                if (e.capacity - e.flow > 0 && parent_node[e.to] == -1) {
                    parent_node[e.to] = curr;
                    parent_edge[e.to] = i;
                    q.push(e.to);
                }
            }
        }
        if (parent_node[sink] == -1) break; // 증가 경로를 못 찾음

        int amount = 1e9;
        for (int v = sink; v != source; v = parent_node[v]) {
            int u = parent_node[v];
            int idx = parent_edge[v];
            amount = min(amount, adj[u][idx].capacity - adj[u][idx].flow);
        }
        for (int v = sink; v != source; v = parent_node[v]) {
            int u = parent_node[v];
            int idx = parent_edge[v];
            int rev_idx = adj[u][idx].rev;
            adj[u][idx].flow += amount;
            adj[v][rev_idx].flow -= amount;
        }
        total_flow += amount;
    }
    return total_flow;
}

void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}