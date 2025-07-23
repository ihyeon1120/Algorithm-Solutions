// Problem: BOJ 11378

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX_SIZE = 2005;
const int INF = INT_MAX;

struct Edge {
    int to, capacity, rev;
};

vector<Edge> adj[MAX_SIZE];
int parent[MAX_SIZE];
int parent_edge_idx[MAX_SIZE];

void add_edge(int s, int e, int w) {
    adj[s].push_back({e, w, (int)adj[e].size()});
    adj[e].push_back({s, 0, (int)adj[s].size() - 1});
}

int edmonds_karp(int source, int sink) {
    int total_flow = 0;
    while(1) {
        fill(parent, parent + MAX_SIZE, -1);
        fill(parent_edge_idx, parent_edge_idx + MAX_SIZE, -1);
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int here = q.front(); q.pop();
            for(int i = 0; i < (int)adj[here].size(); ++i) {
                Edge& e = adj[here][i];
                if(e.capacity > 0 && parent[e.to] == -1) {
                    parent[e.to] = here;
                    parent_edge_idx[e.to] = i;
                    q.push(e.to);
                }
            }
        }
        if (parent[sink] == -1) break;

        int amount = INF;

        for (int p = sink; p != source; p = parent[p]) {
            int prev = parent[p];
            int edge_idx = parent_edge_idx[p];
            amount = min(amount, adj[prev][edge_idx].capacity);
        }

        for(int p = sink; p != source; p = parent[p]) {
            int prev = parent[p];
            int edge_idx = parent_edge_idx[p];

            adj[prev][edge_idx].capacity -= amount;
            int rev_edge_idx = adj[prev][edge_idx].rev;
            adj[p][rev_edge_idx].capacity += amount;
        }

        total_flow += amount;
    }
    return total_flow;
}

void solve() {
    /* 
    source: 0
    직원: 1 ~ n
    일: n+1 ~ n+m+1
    extra source: n+m+3 ~
    sink: n+m+2
    */
    int n, m, k; cin >> n >> m >> k;

    int source = 0;
    int sink = n + m + 2;
    // 기본 업무 노드
    int extra1 = n + m + 3;
    // 벌점 업무 노드
    int extra2 = n + m + 4;

    add_edge(source, extra1, n);
    add_edge(source, extra2, k);

    for (int i = 1; i < n + 1; ++i)
    {
        int j; cin >> j;
        while (j--) { 
            int job; cin >> job;
            add_edge(i, job + n, 1);
        }
        
        add_edge(extra1, i, 1);
        add_edge(extra2, i, k);
    }

    for (int i = 0; i < m; ++i) {
        int job = i + n + 1;
        add_edge(job, sink, 1);
    }

    cout << edmonds_karp(source, sink) << endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}