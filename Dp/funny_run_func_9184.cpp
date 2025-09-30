// Problem: BOJ 9184

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 51;
ll dp[MAXN][MAXN][MAXN];

ll w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (dp[a][b][c] != -1) return dp[a][b][c];
    if (a > 20 || b > 20 || c > 20) {
        dp[a][b][c] = w(20, 20, 20);
        return dp[a][b][c];
    }
    else if (a < b && b < c) {
        dp[a][b][c] = (w(a, b, c-1) + w(a, b - 1, c - 1), w(a, b - 1, c));
        return dp[a][b][c];
    }
    else {
        dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
        return dp[a][b][c];
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill(&dp[0][0][0], &dp[0][0][0] + MAXN*MAXN*MAXN, -1);
    dp[0][0][0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 1; j < MAXN; ++j) {
            for (int k = 1; k < MAXN; ++k) {
                w(i, j, k);
            }
        }
    }

    while(true) {
        int a, b, c; cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        if (a <= 0 || b <= 0 || c <= 0) {
            printf("w(%d, %d, %d) = 1\n", a, b, c);
            continue;
        }
        printf("w(%d, %d, %d) = %d\n", a, b, c, dp[a][b][c]);
    }

    return 0;
}