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
vector<pll> speaker;
ll get_dist(int t) {
    ll ret = 0;
    for (auto& [x, y] : speaker) {
        ret +=  abs(x) + abs(t - y) + 
                abs(t - x) + abs(y) +
                abs(t - x) + abs(t - y) + 
                abs(t - x) + abs(t + y);
    }
    return ret;
}

void solve() {
    ll n, r; cin >> n >> r;
    for (int i = 0; i < n; ++i) {
        ll x, y; cin >> x >> y;
        speaker.push_back({x, y});
    }
    ll p1 = -r; ll p2 = r;
    ll lmid, rmid;
    while(p1 + 2 < p2) {
        lmid = (2*p1 + p2) / 3;
        rmid = (2*p2 + p1) / 3;
        if (get_dist(lmid) > get_dist(rmid)) p1 = lmid;
        else p2 = rmid;
    }
    cout << min({get_dist(p1), get_dist(p2), get_dist(lmid), get_dist(rmid)}) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}