// Problem: BOJ 1912

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
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    vector<int> dp(n, INT_MIN);
    dp[0] = arr[0];
    int ans = dp[0];
    for (int i = 1; i < n; i++) {
        // 이전까지의 최댓값 + arr[i]가 arr[i] 보다 작다면 arr[i]로 dp[i]를 추가
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}