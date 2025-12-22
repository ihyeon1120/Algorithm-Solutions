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
    
    ll total_power = 0; 
    ll total_weight = 0;
    vector<vector<ll>> cost;
    
    for (int i = 0; i < n; ++i) {
        ll w, p; cin >> w >> p;
        total_power += p;     
        cost.push_back({w + p, w, p});
    }
    
    sort(all(cost));
    
    int ans = 0;
    for (vector<ll> a : cost) {
        total_power -= a[2];
        total_weight += a[1];
        if (total_power >= total_weight) {
            ans ++;
        }
        else {
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    while(tc--)
        solve();

    return 0;
}