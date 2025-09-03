// Problem: BOJ 1761

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 40001;
const int LOG_N = (int)ceil(log2(MAXN));

vector<vector<int>> parent(MAXN, vector<int>(LOG_N, 0));
vector<int> depth(MAXN, -1);
vector<int> dist(MAXN, -1);
vector<vector<pii>> graph;

void dfs(int node, int par, int dep, int d) {

    depth[node] = dep;
    dist[node] = d;
    parent[node][0] = par;

    for (pii i : graph[node]) {
        auto [next, w] = i;
        if (next == par) continue;
        dfs(next, node, dep + 1, d + w);
    }
}

void create_table() {
    // parent[x][y] => x의 2^y 부모 저장
    for (int k = 1; k < LOG_N; k++) {
        for (int i = 1; i < MAXN; i++) {
            /*
                희소배열 생성
                parent[i][k-1] -> i의 2^k-1 부모
                parent[parent[i][k-1]][k-1] -> i의 2^k-1 부모의 2^k-1 부모
            */
            parent[i][k] = parent[parent[i][k-1]][k-1];
        }
    }
}

int lca(int u, int v) {
    // u가 더 깊게
    if (depth[u] < depth[v])
        swap(u, v);
    // u와 v의 깊이를 맞추는 반복문
    for (int k = LOG_N - 1; k >= 0; k--) {
        // u가 v보다 더 깊거나 같지만 점프뛸 수 있는 최대로 뛰기
        if (depth[u] - (1 << k) >= depth[v]) {
            u = parent[u][k];
        }
    }

    if (u == v) return u;

    for (int k = LOG_N - 1; k >= 0; k--) {
        // 조상이 아직까지 다르다면 점프
        if (parent[u][k] != parent[v][k]) {
            u = parent[u][k];
            v = parent[v][k];
        }
    }

    return parent[u][0];
}

void solve() {
    int N; cin >> N;
    graph.assign(N+1, vector<pii>());
    N--;
    while (N--) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    dfs(1, 0, 0, 0);
    create_table();
    int M; cin >> M;
    while (M--)
    {
        int a, b; cin >> a >> b;
        cout << dist[a] + dist[b] - (2 * dist[lca(a, b)]) << endl;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    
    return 0;
}