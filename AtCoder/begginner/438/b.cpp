
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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    string t; cin >> t;
    int ans = (1 << 30);
    for (int i = 0; i < n - m + 1; ++i) {
        string sub = s.substr(i, m);
        int temp = 0;
        for (int j = 0; j < m; ++j) {
            int tt = t[j] - '0';
            int ss = sub[j] - '0';
            int diff = (ss - tt + 10) % 10;
            temp += diff;
        }
        ans = min(ans, temp);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}