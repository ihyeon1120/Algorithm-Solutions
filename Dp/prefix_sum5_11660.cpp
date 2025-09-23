// Problem: BOJ 11660

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
    vector<vector<int>> arr(n+1, vector<int>(n+1, 0));

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++){
            int t; cin >> t;
            arr[i][j] = arr[i][j-1] + t;
        }
    }

    while(m--) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        int ans = 0;
        for (int i = r1; i <= r2; ++i) {
            ans += arr[i][c2] - arr[i][c1 - 1];
        }
        cout << ans << endl;
    }
    

    return 0;
}