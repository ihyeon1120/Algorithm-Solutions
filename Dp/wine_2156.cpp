// Problem: BOJ 2156

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
    vector<int> arr(n + 1, 0);
    for (int i = 1; i < n + 1; ++i) cin >> arr[i];
    vector<int> dp(n+1, 0);
    dp[1] = arr[1];
    dp[2] = arr[2] + dp[1];
    for (int i = 3; i < n + 1; ++i) {
        // XO , OO , OX
        // 안먹는 것을 고려하지 않아서 틀림
        dp[i] = max({dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i], dp[i-1]});
    }
    cout << dp[n] << endl;
    return 0;
}