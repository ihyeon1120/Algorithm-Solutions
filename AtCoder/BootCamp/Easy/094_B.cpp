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
    int n, m, x; cin >> n >> m >> x;
    int to0 = 0;
    int toN = 0;
    while (m--) {
        int t; cin >> t;
        to0 += (t < x);
        toN += (x < t);
    }
    cout << min(to0, toN) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}