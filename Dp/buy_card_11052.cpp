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

    int n; cin >> n;
    vector<int> cards(n+1, 0);
    for (int i = 1; i < n + 1; ++i) cin >> cards[i];

    vector<int> dp(n+1, 0);
    // dp[i] = i 개의 카드로 구성할 수 있는 최대 가치
    for (int i = 1; i < n + 1; i ++) {
        for (int j = 1; j <= i; ++j) {
            dp[i] = max(dp[i], cards[j] + dp[i - j]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}