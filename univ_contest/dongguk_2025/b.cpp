// Problem: B

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
    int t; cin >> t;
    int ans = 0;
    while(t--) {
        int s, c, a, r; cin >> s >> c >> a >> r;
        if (s >= 1000) {
            ans ++;
        }
        else if (c >= 1600) {
            ans ++;
        }
        else if (a >= 1500) {
            ans ++;
        }
        else if (r != -1 && r <= 30) {
            ans ++;
        }
    }
    cout << ans << endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}