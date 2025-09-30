#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i< n; ++i) cin >> arr[i];
        sort(all(arr));
        ll ans = LONG_LONG_MIN;
        for (int i = 0; i < n; i += 2) {
            ans = max(ans, abs(arr[i] - arr[i + 1]));
        }
        cout << ans << endl;
    }

    return 0;
}