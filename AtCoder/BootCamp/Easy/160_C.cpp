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
    int k, n; cin >> k >> n;
    vector<int> pos(n);
    int m = -1;
    for (int i = 0; i < n; ++i) cin >> pos[i];
    for (int i = 0; i < n; ++i) {
        m = max(m, (pos[i] - pos[(i - 1 + n) % n] + k) % k);
    }
    cout << k - m << endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}