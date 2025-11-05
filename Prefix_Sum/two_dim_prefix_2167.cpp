// Problem: BOJ 2167

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vector<ll>> prefix(n+1, vector<ll>(m+1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x; cin >> x;
            prefix[i+1][j+1] = prefix[i+1][j] + prefix[i][j+1] - prefix[i][j] + x; 
        }
    }

    int t; cin >> t;
    while(t--) {
        int sr, sc, er, ec; cin >> sr >> sc >> er >> ec;
        cout << prefix[er][ec] + prefix[sr-1][sc-1] - prefix[er][sc-1] - prefix[sr-1][ec] << endl;
    }

    return 0;
}