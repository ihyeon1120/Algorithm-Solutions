// Problem: BOJ 1789

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

    ll n; cin >> n;
    int i;
    for (i = 1; n > 0; ++i) {
        n -= i;
    }
    // 딱 맞아 떨어지지 않는다면 불필요하게 i에다 +1하게 됨
    if (n < 0) i--;
    cout << i - 1 << endl;

    return 0;
}