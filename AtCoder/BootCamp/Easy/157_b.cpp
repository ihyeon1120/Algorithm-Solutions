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
    int n = 3;
    unordered_map<ll, pii> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ll t; cin >> t;
            mp.insert({t, {i, j}});
        }
    }
    int m; cin >> m;
    vector<vector<bool>> check(8, vector<bool>(3, false));
    vector<int> a(m);
    for (int i = 0; i < m; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int t = a[i];
        if (!mp.count(t)) continue;
        auto [r, c] = mp[t];
        check[c][r] = true;
        check[r+3][c] = true;
        if (r == c) check[6][r] = true;
        if (2 - r == c) check[7][r] = true;
    }
    for (int i = 0; i < 8; ++i) {
        if (check[i][0] && check[i][1] && check[i][2]) {cout << "Yes" << endl; return;} 
    }
    cout << "No" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}