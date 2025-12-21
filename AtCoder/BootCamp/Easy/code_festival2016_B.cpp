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
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    vector<int> cnt(3, 0);
    for (char c : s ) {
        bool flag = false;
        if (c == 'a') {
            if ((cnt[0] + cnt[1]) >= (a + b)) {
            }
            else {
                cnt[0]++;
                flag = true;

            }
        }
        else if (c == 'b') {
            if ((cnt[0] + cnt[1]) >= (a + b) || cnt[1] >= b) {}
            else {
                cnt[1]++;
                flag = true;

            }
        }
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}