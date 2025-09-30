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
        int ans = 0;
        int k = 0;
        while(n--) {
            int t; cin >> t;
            if (t == 0) ans ++;
            else if (t == -1) k++;
        }
        if (k % 2 == 1) ans += 2;
        cout << ans << endl;
    }

    return 0;
}