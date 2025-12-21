#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll f(int p, const vector<int> &a) {
    ll ret = 0;
    for (int i = 0; i < sz(a); ++i) {
        ret += (a[i] - p) * (a[i] - p);
    }
    return ret;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l = -1; int r = 101;
    while(l + 2 < r) {
        int left_mid = (2*l + r) / 3;
        int right_mid = (2*r + l) / 3;
        if (f(left_mid, a) < f(right_mid, a)) {
            r = right_mid;
        }
        else {
            l = left_mid;
        }
    }
    cout << min({f(l, a), f(l+1, a), f(l+2, a), f(r, a)}) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}