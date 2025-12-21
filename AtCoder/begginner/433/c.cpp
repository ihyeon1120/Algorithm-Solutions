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
    int n = sz(s);
    int ans = 0;
    for (int i = 0; i < n - 1; ++ i) {
        if (s[i] == (s[i+1] - 1)) {
            int len = 1;
            ans ++;
            while (i - len >= 0 && i + len + 1 < n) {
                if (s[i - len] == s[i] && s[i+1] == s[i + 1 + len]) {
                    ans ++;
                } else {
                    break;
                }
                len ++;
            }
        }
    }
    cout << ans << endl;
}

void solve1() {
    string s; cin >> s;
    int n = sz(s);
    int ans = 0;
    int prev_cnt = 1;
    int cur = s[0] - '0';
    for (int i = 1; i < n ; ++i) {
        if (cur == s[i] - '0') prev_cnt ++;
        else if (cur + 1 == s[i] - '0') { 
            int j;
            int next_cnt = 0;
            for (j = i; j < n && s[i] == s[j]; ++j) {
                next_cnt++;
            }
            i = j - 1;
            ans += min(prev_cnt, next_cnt);
            prev_cnt = next_cnt;
            cur = s[i] - '0';
        }
        else {
            cur = s[i] - '0';
            prev_cnt = 1;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    // solve();
    solve1();
    return 0;
}