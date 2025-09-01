// Problem: BOJ 11266

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 10001;

vector<vector<int>> adj;
vector<int> discovered;
vector<int> is_cut_vertex;
int vertex_cnt = 0;

int find_cut_vertex(int cur, int is_root) {
    int low = discovered[cur] = vertex_cnt++;
    int child = 0;

    for (int next : adj[cur]) {
        if (discovered[next] == -1) {
            ++child;
            int subtree = find_cut_vertex(next, false);
            // 서브트리 중에서 나보다 먼저 나온 정점으로 가지 못하면 절단점
            if (is_root == 0 && subtree >= discovered[cur]) 
                is_cut_vertex[cur] = 1;
            low = min(low, subtree);
        }
        else {
            low = min(low, discovered[next]);
        }
    }

    if(is_root == 1) is_cut_vertex[cur] = (child >= 2);
    return low;

}

void solve() {
    int v, e; cin >> v >> e;
    adj.assign(v+1, vector<int>());
    discovered.assign(MAXN, -1);
    is_cut_vertex.assign(MAXN, 0);
    while(e--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= v; ++i) {
        if (discovered[i] == -1) {
            find_cut_vertex(i, 1);
        }
    }

    int cnt = accumulate(all(is_cut_vertex), 0);
    cout << cnt << endl;
    for (int i = 1; i < v + 1; ++i) {
        if (is_cut_vertex[i]) 
            cout << i << " ";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}