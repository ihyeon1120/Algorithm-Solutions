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
    string t; cin >> t;
    vector<int> s_cnt(26, 0);
    vector<int> t_cnt(26, 0);
    for (char c : s) {
        s_cnt[c-'a']++;
    }
    for (char c : t) {
        t_cnt[c-'a'] ++;
    }
    for (int i = 0; i < 26; ++i) {
        if (s_cnt[i] > 0 && s_cnt[i] > t_cnt[i]) {
            cout << "Impossible" << endl;
            return;
        }
        else if (s_cnt[i] > 0 && s_cnt[i] <= t_cnt[i]) {
            t_cnt[i] -= s_cnt[i];
        }
    }
    string new_s = "";
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < t_cnt[i]; ++j) {
            new_s.push_back((char)(i + 'a'));
        }
    }
    string ans = "";
    int i = 0; int j = 0;
    while (sz(ans) != sz(t) && i < sz(new_s) && j < sz(s)) {
        if (new_s[i] < s[j]) {
            ans.push_back(new_s[i++]);
        }
        else if (new_s[i] > s[j]) {
            ans.push_back(s[j++]);
        }
        else {
            char prev = s[j];
            int k;
            for (k = j + 1; k < sz(s); ++k) {
                if (prev < s[k]) break;
            }
            for (;j < k; ++j) {
                ans.push_back(s[j]);
            }
        }
    }
    while(i < sz(new_s)) {
        ans.push_back(new_s[i++]);
    }
    while(j < sz(s)) {
        ans.push_back(s[j++]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    while(tc--)
        solve();

    return 0;
}