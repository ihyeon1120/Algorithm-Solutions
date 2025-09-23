// Problem: BOJ 14501

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
    vector<pii> arr(n);
    for (int i = 0; i < n; i++)
    {
        int t, p; cin >> t >> p;
        arr[i] = {t, p};
    }
    
    // 10 20 20 30 45 45 45
    vector<int> dp(n + 2, 0);

    int ans = 0;

    for (int i = n; i > 0; --i) {
        auto [t, p] = arr[i - 1];
        // 일이 끝나는 시점 = i + t - 1
        if (i + t - 1<= n) {
            dp[i] = max(dp[i + t] + p, dp[i + 1]);
        } else {
            // i일에 상담을 하지 못하면 i + 1일의 최대 수익
            dp[i] = dp[i + 1];
        }
    }
    cout << dp[1] << endl;
    return 0;
}