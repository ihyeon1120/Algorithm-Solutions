// Problem: BOJ 16319

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
    vector<vector<int>> cnt(26, vector<int>(sz(s) + 1, 0));
    for (int i = 1; i <= sz(s); ++i) {
        char c = s[i-1];
        cnt[c - 'a'][i]++;  
    }
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < sz(s); ++j) {
            cnt[i][j+1] += cnt[i][j] ;
        }
    }
    int q; cin >> q;
    while(q--) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        cout << cnt[c-'a'][r+1] - cnt[c-'a'][l] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}