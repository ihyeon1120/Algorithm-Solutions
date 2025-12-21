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
    ll n, x; cin >> n >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(all(v));
    int i;
    for (i = 0; i < n - 1; ++i) {
        if (x - v[i] < 0) break;
        x -= v[i];
    }
    if (x == v[n-1]) ++i;
    cout << i << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}