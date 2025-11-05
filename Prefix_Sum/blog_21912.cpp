// Problem: BOJ 21912

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
    int n, x; cin >> n >> x;
    vector<ll> pf(n+1, 0);
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        pf[i+1] = pf[i] + t;
    }
    int max_n = 0;
    int cnt = 0;
    for (int i = 0; i < n - x + 1; ++i) {
        int total = pf[i + x] - pf[i];
        if (total > max_n) {
            max_n = total;
            cnt = 1;
        }
        else if (total == max_n) cnt++;
    }
    if (max_n == 0) {
        cout << "SAD" << endl;
        return;
    }
    cout << max_n << endl;
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}