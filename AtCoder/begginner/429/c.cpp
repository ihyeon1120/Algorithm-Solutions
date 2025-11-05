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
    ll n; cin >> n;
    vector<ll> v(n);
    unordered_map<ll, ll> m;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        v[i] = t;
        m[t]++;
    }
    for (auto& [key, value] : m) {
        if (value < 2) continue;
        // value Comb 2 * n - value
        ans += ((value * (value - 1)) / 2) * (n - value);
    }
    
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}