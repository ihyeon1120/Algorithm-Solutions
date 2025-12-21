// Problem:  

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll t;
ll get_pos(ll diff) {
    int m = -diff / t;
    return (diff + (t * (m + 1))) % t;
}

void solve() {
    int n; cin >> n >> t;
    vector<vector<ll>> pf(n+1, vector<ll>(2, 0));
    vector<string> b(n);
    ll pre = 0;
    for (int i = 0; i < n; ++ i) {
        string s; cin >> s;
        ll pos; cin >> pos;
        b[i] = s;
        pf[i+1] = {pf[i][0] - pos, i};

    }
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
        pf[i+1][0] = get_pos(pf[i+1][0]);
    }
    sort(all(pf));
    vector<string> ans; 
    for (int i = 1; i < n + 1; ++i) {
        if (i == n) {
            ll diff = (pf[1][0] - pf[i][0] + t) % t;
            if (diff > 0 && diff <= 1000) ans.push_back(b[pf[i][1]]);
            break;
        }
        ll diff = (pf[i+1][0] - pf[i][0] + t) % t;
        if (diff > 0 && diff <= 1000) {
            ans.push_back(b[pf[i][1]]);
        }
    }
    if (sz(ans) == 0) {
        cout << -1 << endl;
        return;
    }
    sort(all(ans));
    for (string temp : ans) cout << temp << " ";


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}