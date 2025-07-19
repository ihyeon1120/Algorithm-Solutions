// Problem: BOJ 6086

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX_NODES = 52;
const int INF = INT_MAX;

struct Edge
{
    int to;
    int capacity;
    int rev;
};

vector<Edge> adj[MAX_NODES];
int parent[MAX_NODES];
int parent_edge_idx[MAX_NODES];

int ctoi(char a) {
    if ('A' <= a && a <= 'Z') return a - 'A';
    return a - 'a' + 26;
}

void add_edge(int s, int e, int w) {
    adj[s].push_back({e, w, (int)adj[e].size()});
    adj[e].push_back({s, w, (int)adj[s].size()});
}

int edmonds_karp(int source, int sink) {
    int total_flow = 0;
    while(1) {
        fill(parent, parent + MAX_NODES, -1);
        fill(parent_edge_idx, parent_edge_idx + MAX_NODES, -1);
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int here = q.front(); q.pop();
            for(int i = 0; i < adj[here].size(); ++i) {
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
    int n; cin >> n;
    while (n--)
    {
        char cs, ce;
        int w;
        cin >> cs >> ce >> w;
        int s = ctoi(cs);
        int e = ctoi(ce);
        add_edge(s, e, w);
    }
    cout << edmonds_karp(ctoi('A'), ctoi('Z')) << endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}