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
vector<bool> visited;

void add_edge(int from, int to, int cap) {
    adj[from].push_back({to, cap, 0, sz(adj[to])});
    adj[to].push_back({from, 0, 0, sz(adj[from]) - 1});
}
// DFS를 통해 증가 경로 찾기
int dfs(int curr, int sink, int min_cap) {
    if (curr == sink) return min_cap;
    visited[curr] = true;
    for (auto &edge : adj[curr]) {
        int residual = edge.capacity - edge.flow;
        if (!visited[edge.to] && residual > 0) {
            int d = dfs(edge.to, sink, min(min_cap, residual));
            if (d > 0) {
                edge.flow += d;
                adj[edge.to][edge.rev].flow -= d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int source, int sink) {
    int total_flow = 0;
    while(1) {
        fill(all(visited), false);
        int flow = dfs(source, sink, 1e9);
        if (flow == 0) break;
        total_flow += flow;
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