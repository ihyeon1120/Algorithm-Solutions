
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
    int n, q; cin >> n >> q;
    string s; cin >> s;
    int sz = sz(s);
    bool has_b = false;
    for (char c : s) {
        if (c == 'B') {
            has_b = true;
            break;
        }
    }
    
    while(q--) {
        ll a; cin >> a;
        if (!has_b) {
            cout << a << endl;
            continue;
        }
        int ans = 0;
        int cur = 0;
        while(a > 0) {
            if (s[cur] == 'B') {
                a /= 2;
                cur++;
                ans++;
            }
            else {
                int cnt = 0;
                while(cur + cnt < sz && s[cur + cnt] == 'A') {
                    cnt++;
                }
                ans += min(a, (ll)cnt);
                cur += min(a, (ll)cnt);
                a -= min(a, (ll)cnt);
            }
            cur %= sz;
        }
        cout << ans << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    while(tc--) solve();

    return 0;
}