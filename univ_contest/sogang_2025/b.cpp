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
    vector<int> cnt(4, 0);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        cnt[t-1] ++;
    }
    ans += cnt[3];
    ans += cnt[2];
    cnt[0] -= cnt[2];
    ans += (int)ceil(cnt[1] / 2.0);
    if (cnt[1] % 2 == 1) cnt[0] -= 2;
    if (cnt[0] < 0) cnt[0] = 0;
    ans += (int)ceil(cnt[0] / 4.0);
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