// Problem: BOJ 13305

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool cmp(const pll &a, const pll &b) {
    return a.first < b.first;
}

void solve() {
    int n; cin >> n;
    ll d = 0;
    // 누적거리
    vector<ll> dist(n);
    vector<pll> costs(n);
    dist[0] = d;
    for (int i = 1; i < n; ++i) {
        ll t; cin >> t;
        d += t;
        dist[i] = d;
    }
    for (int i = 0; i < n; ++i) {
        int c; cin >> c;
        costs[i] = {c, i};
    }
    sort(costs.begin(), costs.end()-1, cmp);

    ll ans = 0;
    int cur_station = n-1;
    for (int i = 0; i < n-1; ++i) {
        auto [cost, station] = costs[i];
        if (cur_station > station) {
            ans += (cost) * (dist[cur_station] - dist[station]);
            cur_station = station;
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