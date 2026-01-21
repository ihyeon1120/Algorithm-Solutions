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
    ll w, h ,d; cin >> w >> h >> d;
    ll n; cin >> n;
    ll wc, hc, dc;
    ll nn = n;
    wc = gcd(w, n);
    n = n / gcd(w, n);
    hc = gcd(h, n);
    n = n / gcd(h, n);
    dc = gcd(d, n);
    if (wc * hc * dc != nn) {cout << -1 << endl; return;}
    cout << wc-1 << " " << hc-1 << " " << dc-1 << " " << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}