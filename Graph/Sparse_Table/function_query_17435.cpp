// Problem: BOJ 17435

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
    int m; cin >> m;
    const int logM = 32;
    vector<int> f(m+1);
    vector<vector<int>> table(logM, vector<int>(m+1, 0));
    for (int i = 1; i <= m; ++i) cin >> f[i];
    for (int i = 1; i <= m; ++i) table[0][i] = f[i];
    for (int i = 1; i < logM; ++i) {
        for (int j = 1; j <= m; ++j) {
            table[i][j] = table[i-1][table[i-1][j]];
        }
    }
    int q; cin >> q;
    while(q--) {
        int n, x; cin >> n >> x;
        int node = x;
        for (int i = 0; i < logM; ++i) {
            if ((n >> i) & 1) {
                node = table[i][node];
            }
        }
        cout << node << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}