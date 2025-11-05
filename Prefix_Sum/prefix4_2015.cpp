// Problem: BOJ 2015

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
    ll N, K; cin >> N >> K;
    vector<ll> pf(N+1, 0);
    map<ll, ll> cnt;
    cnt[0]++;
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        pf[i+1] = pf[i] + t;
        ans += cnt[pf[i+1] - K];
        cnt[pf[i+1]] ++;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}