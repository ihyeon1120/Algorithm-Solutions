// Problem: BOJ 14916

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

    int c1 = 5;
    int c2 = 2;

    int n; cin >> n;

    int cc1 = ((n + c1 - 1) / c1);
    int cc2 = 0;
    n -= cc1 * c1;

    while(1) {
        if (n == 0) break;
        if (cc1 < 0) break;
        else if (n < 0) {
            cc1 -= 1;
            n += c1;
        } else if (n > 0) {
            cc2 += 1;
            n -= 2;
        }
    }

    if (n == 0) cout << cc1 + cc2 << endl;
    else cout << -1 << endl;

    return 0;
}