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

    vector<int> coins = {500, 100, 50, 10, 5, 1};
    int n; cin >> n;
    n = 1000 - n;
    int ans = 0;
    for (int coin : coins) {
        int t = n / coin;
        n -= t * coin;
        ans += t;
    }
    cout << ans << endl;
    return 0;
}