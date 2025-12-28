#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
/*
    1 4 2 4 3 -> 1 5 7 11 3
    2 3 4 2 2 -> 2 5 9 11 13 -> 11 8 4 2
    3 2 4 4 3 -> 3 5 9 13 16
*/
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    vector<ll> pa(n+1, 0);
    vector<ll> pb(n+1, 0);
    vector<ll> pc(n+1, 0);
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        a[i] = t;
        pa[i+1] = pa[i] + t;
    }
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        b[i] = t;
        pb[i+1] = pb[i] + t;
    }
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        c[i] = t;
        pc[i+1] = pc[i] + t;
    }
    vector<ll> diff(n+1, 0);
    vector<ll> max_diff(n+1, -1e18);
    for(int i = 1; i <= n; ++i) {
        diff[i] = diff[i-1] + (a[i-1] - b[i-1]);
        if (i == 1) max_diff[i] = diff[i];
        else max_diff[i] = max(max_diff[i-1], diff[i]);
    }
    ll ans = -1;
    for (int i = 2; i < n; ++i) {
        ll t = max_diff[i-1] + pb[i] + pc[n] - pc[i];
        ans = max(ans, t);
    }
    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}