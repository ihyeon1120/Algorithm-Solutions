// Problem: BOJ 10211

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
    int n; cin >> n;
    vector<ll> pf(n+1, 0);
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        pf[i+1] = pf[i] + t;
    } 
    ll m = LONG_LONG_MIN;
    for (int len = 1; len <= n; ++len) {
        for (int s = 0; s < n - len + 1; ++s) {
            m = max(m, pf[s+len] - pf[s]);
        }
    }
    cout << m << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) 
        solve();

    return 0;
}