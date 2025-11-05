// Problem: BOJ 11441

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
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        cout << pf[r] - pf[l-1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}