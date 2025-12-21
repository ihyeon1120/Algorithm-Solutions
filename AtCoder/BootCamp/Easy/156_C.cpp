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
    vector<int> arr(n);
    int m = 0;
    int ans = 1<<30;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        arr[i] = t;
        m += t;
    }
    m /= n;
    int t = 0;
    for (int i = 0; i < n; ++i) {
        t += (arr[i] - m) * (arr[i] - m);
    }
    ans = min(ans, t);
    m += 1;
    t = 0;
    for (int i = 0; i < n; ++i) {
        t += (arr[i] - m) * (arr[i] - m);
    }
    ans = min(ans, t);
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