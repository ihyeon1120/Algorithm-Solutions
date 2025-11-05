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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];
    unordered_set<string> sub;
    for (int r = 0; r < n - m + 1; ++r) {
        for (int c = 0; c < n - m + 1; ++c) {
            string t;
            for (int i = r; i - r < m; ++i) {
                for (int j = c; j - c < m; ++j) {
                    t.push_back(grid[i][j]);
                }
            }
            sub.insert(t);
        }
    }

    cout << sz(sub) << endl;
    

    return 0;
}