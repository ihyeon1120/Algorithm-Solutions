// Problem: BOJ 2143

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
    ll t; cin >> t;
    int n; cin >> n;
    vector<ll> pfA(n+1, 0);
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        pfA[i+1] = pfA[i] + k;
    }
    int m; cin >> m;
    vector<ll> pfB(m+1, 0);
    for (int i = 0; i < m; ++i) {
        int k; cin >> k;
        pfB[i+1] = pfB[i] + k;
    }

    map<ll, int> cnt_A;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            cnt_A[pfA[j] - pfA[i]]++;


    ll ans = 0;
    for (int i  = 0; i < m; ++i) {
        for (int j = i + 1; j <= m; ++j) {
            ll pf = pfB[j] - pfB[i];
            ans += cnt_A[t- pf];
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