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
    string s; cin >> s;
    int ans = 0;
    int n = sz(s);
    for (int i = 0; i < n; ++i) {
        int t = 0;
        for (int j = i; j < n; ++j) {
            if (s[j] == 'A' || s[j] == 'T' || s[j] == 'C' || s[j] == 'G') t++;
            else break;
        }
        ans = max(ans, t);
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