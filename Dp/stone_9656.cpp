// Problem: BOJ 9656

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int M = 1001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    // 0 -> sk, 1 -> cy
    vector<int> dp(M, -1);
    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 0;
    

    return 0;
}