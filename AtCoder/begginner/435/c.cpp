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
    int n; cin >> n;
    vector<int> dominos(n);
    for (int i = 0; i < n; ++i) cin >> dominos[i];
    int ans = 1;
    int cur = dominos[0] - 1;
    for (int i = 1; cur > 0 && i < n; ++i) {
        cur = max(cur-1, dominos[i] - 1);
        ans ++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}