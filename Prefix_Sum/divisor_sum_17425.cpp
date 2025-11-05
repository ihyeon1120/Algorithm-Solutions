// Problem: BOJ 17425

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1000001;

void solve() {
    // f(A)의 시간 복잡도 = root(A)
    // g(N)의 시간 복잡도 = Nroot(N) -> TLE 다른 방법
    vector<ll> dp(MAXN, 0);
    for (int i = 1; i < MAXN; ++i) {
        for (int j = i; j < MAXN; j += i) {
            dp[j] += i;
        }
    }
    for (int i = 1; i < MAXN; ++i) {
        dp[i] += dp[i-1];
    }
    int t; cin >> t;
    while(t--) {
        int k; cin >> k;
        cout << dp[k] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}