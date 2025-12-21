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
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> a;
    vector<ll> b;
    priority_queue<ll> pq;
    ll s; cin >> s;
    for (int i = 1; i < n; ++i) {
        ll t; cin >> t;
        ll diff = t - s;
        if ((y * diff) % (x - y) != 0) {
            cout << -1 << endl;
            return;
        }
        ll temp = (y * diff) / (x - y);
        a.push_back(temp);
        b.push_back(t);
        pq.push(temp);
    }
    ll tar = pq.top() < 0 ? 0 : pq.top();
    ll ans = s - tar;
    for (int i = 0 ; i < n - 1; ++i) {
        ll cur = tar - a[i];
        if (cur< 0 || cur > b[i]) {
            cout << - 1 << endl;
            return;
        }
        ans += b[i] - cur;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}