// Problem: BOJ 9465

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
    int dp[2][n] = {0};
    int arr[2][n];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    dp[0][0] = arr[0][0];
    dp[1][0] = arr[1][0];
    for (int c = 1; c < n; c++) {
        // 점화식 아이디어: 대각선에 누적하는 방식, 대각선은 지금까지의 최댓값을 누적
        dp[0][c] = max(dp[0][c-1], dp[1][c-1] + arr[0][c]);
        dp[1][c] = max(dp[1][c-1], dp[0][c-1] + arr[1][c]);
    }
    cout << max(dp[0][n-1], dp[1][n-1]) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    while(n--) solve();

    return 0;
}