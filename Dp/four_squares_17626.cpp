    // Problem: BOJ 17626

    #include <bits/stdc++.h>

    #define endl "\n"
    #define ends " "
    #define sz(x) (int)(x).size()
    #define all(x) (x).begin(), (x).end()

    using namespace std;

    typedef long long ll;
    typedef pair<int, int> pii;
    typedef pair<ll, ll> pll;

    const int MAXN = 50001;

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> dp(MAXN, (1<<30));
        dp[1] = 1;
        for (int i = 2; i < MAXN; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                if (j * j == i) {
                    dp[i] = 1;
                    break;
                }
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        int n; cin >> n;
        cout << dp[n];

        return 0;
    }