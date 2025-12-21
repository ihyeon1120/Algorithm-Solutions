// Problem: BOJ 9471

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
    int t, m; cin >> t >> m;
    ll prev = 0; ll cur = 1;
    for (int i = 1; ; ++i) {
        ll next = (prev + cur) % m;
        prev = cur;
        cur = next;
        if (prev == 0 && next == 1) {
            cout << t << " " << i << endl;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}