// Problem: BOJ 11409

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 802;
const int INF = 1 << 30;

struct Edge {
    int to, cap, rev, cost;
};

vector<Edge> adj[MAXN];
int parent[MAXN]; int parent_idx[MAXN];
int dist[MAXN]; bool inq[MAXN];
// 음수 사이클 감지
int path_count[MAXN];

void add_edge(int s, int e, int cap, int cost) {
    adj[s].push_back({e, cap, (int)adj[e].size(), cost});
    adj[e].push_back({s, 0, (int)adj[s].size() - 1, -cost});
}

void fill_arr() {
    fill(parent, parent + MAXN, -1);
    fill(parent_idx, parent_idx + MAXN, -1);
    fill(dist, dist + MAXN, INF);
    fill(inq, inq + MAXN, false);
    fill(path_count, path_count + MAXN, 0);
}

void max_flow(int source, int sink) {
    int total_flow = 0;
    int total_cost = 0;
    while (1)
    {
        fill_arr();
        queue<int> q;
        q.push(source);
        dist[source] = 0;
        inq[source] = true;
        path_count[source] = 1;

        while (!q.empty())
        {
            int cur = q.front(); q.pop();
            inq[cur] = false;
            for(int i = 0; i < (int)adj[cur].size(); ++i) {
                Edge &next = adj[cur][i];
                // 잔여 용량 확인
                if (next.cap > 0) {
                    // 최단 거리 갱신
                    if (dist[next.to] > dist[cur] + next.cost) {
                        dist[next.to] = dist[cur] + next.cost;
                        parent[next.to] = cur;
                        parent_idx[next.to] = i;
                        // 큐에 다음 노드가 없다면 추가
                        if (!inq[next.to]) {
                            inq[next.to] = true;
                            q.push(next.to);
                            path_count[next.to]++;
                            if (path_count[next.to] >= MAXN) return;
                        }
                    }
                } 
            }
        }
        if (parent[sink] == -1) break;
        int amount = INF;
        for (int p = sink; p != source; p = parent[p]) {
            int prev = parent[p];
            int idx = parent_idx[p];
            amount = min(amount, adj[prev][idx].cap);
        }
        for (int p = sink; p != source; p = parent[p]) {
            int prev = parent[p];
            int idx = parent_idx[p];

            adj[prev][idx].cap -= amount;
            int rev_idx = adj[prev][idx].rev;
            adj[p][rev_idx].cap += amount;
        }

        total_flow += amount;
        total_cost += dist[sink] * amount;

    }
    cout << total_flow << endl << -total_cost << endl;
}

void solve() {
    // source: 0, sink: 801
    int n, m; cin >> n >> m;
    int source = 0; int sink = 801;
    int job_start = 400;
    for(int i = 1; i < n + 1; i ++) {
        add_edge(source, i, 1, 0);
        int k; cin >> k;
        while(k--) {
            int job, cost; cin >> job >> cost;
            add_edge(i, job + job_start, 1, -cost);
        }
    }

    for(int i = 1; i < m+1; i ++) add_edge(job_start + i, sink, 1, 0);
    max_flow(source, sink);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}