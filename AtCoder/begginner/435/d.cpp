#include <bits/stdc++.h>
using namespace std;

static const int MAX = 300000;
vector<int> adj[MAX + 1];
bool parent_color[MAX + 1];
int n, m, q;

void dfs(int cur) {
    parent_color[cur] = true;
    for (int nxt : adj[cur]) {
        if (!parent_color[nxt]) dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a); // 역방향 저장
    }

    cin >> q;
    while (q--) {
        int t, v;
        cin >> t >> v;
        if (t == 1) {
            if (!parent_color[v]) dfs(v);
        } else { // t == 2
            cout << (parent_color[v] ? "Yes" : "No") << "\n";
        }
    }
    return 0;
}
