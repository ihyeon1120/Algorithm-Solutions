#include <bits/stdc++.h>
using namespace std;

int n, rem, ans = 0;
vector<vector<int>> adj;
int root = -1;

void dfs(int node) {
    if (node == rem) return;

    bool isLeaf = true;
    for (int next : adj[node]) {
        if (next == rem) continue;
        dfs(next);
        isLeaf = false;
    }

    if (isLeaf) ans++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    adj.assign(n, {}); 
    vector<int> parent(n);

    for (int i = 0; i < n; i++) {
        cin >> parent[i];
        if (parent[i] == -1) root = i; // 루트 기록
    }

    cin >> rem;

    if (rem == root) {
        cout << 0 << "\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (i == rem) continue;              
        if (parent[i] == -1 || parent[i] == rem) continue; 
        adj[parent[i]].push_back(i);
    }

    dfs(root);
    cout << ans << "\n";
}
