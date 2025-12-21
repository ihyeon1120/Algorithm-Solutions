// Problem: B

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 101;

ll sum_digit(ll x) {
    ll ret = 0;
    while(x > 0) {
        ret += (x % 10);
        x /= 10;
    }
    return ret;
}

void solve() {
    vector<ll> dp(MAXN, 0);
    dp[0] = 1;
    int n; cin >> n;
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] += sum_digit(dp[j]);
        }
    }
    cout << dp[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}