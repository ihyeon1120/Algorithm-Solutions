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
    int a, b, c; cin >> a >> b >> c;
    int ta, tb, tc;
    ll i = 0;
    while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
        i++;
        ta = b/2 + c/2;
        tb = a/2 + c/2;
        tc = a/2 + b/2;
        if (ta == a && tb == b && tc == c) {
            i = -1;
            break;
        }
        a = ta; b = tb; c = tc;
    }
    cout << i << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}