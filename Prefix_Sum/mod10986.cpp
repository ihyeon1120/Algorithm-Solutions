// Problem: BOJ 10986

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<vector<ll>> dp;

ll comb2(ll n) {
    if (n < 2) return 0;
    return (n * (n-1)) / 2;
}

void solve() {
    int N, M; cin >> N >> M;
    vector<ll> pf(N+1, 0);
    vector<int> mod_cnt(M, 0);
    dp = vector<vector<ll>>(M+1 , vector<ll>(M+1, -1));
    /*
        a = 1 2 3 1 2
        s = 1 3 6 7 9
        m = 1 0 0 1 0
        0이 4개 0이 아닌개 2개 -> n개 중에서 2개만 고를 수 있음
    */
    for (int i = 0; i < N; ++i) {
        ll t; cin >> t;
        pf[i+1] = pf[i] + t;
        int mod = ((pf[i + 1] % M) + M) % M;
        mod_cnt[mod]++;
    }
    ll ans = mod_cnt[0];
    for (ll i : mod_cnt) {
        ans += comb2(i);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}