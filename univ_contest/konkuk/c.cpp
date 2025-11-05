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

const int M = 100001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> dp(M);
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i < M; ++i) {
        dp[i] = dp[i-1] + i;
    }
    int n; cin >> n;
    cout << dp[n] << endl;
    return 0;
}