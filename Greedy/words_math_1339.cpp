// Problem: BOJ 1339

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

    map<char, int> defalut_dict;
    const int MAXN = 8;
    int n; cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        words[i] = s;
        for (int i = sz(s) - 1; i > -1; i--) {
            
        }
    }

    int k = 9;
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < n; ++j) {
            if (words[j][i] == '0') continue;
            if (defalut_dict[words[j][i]] == 0) defalut_dict[words[j][i]] = k--;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll temp = 0;
        for (int j = 0; j < MAXN; ++j) {
            if (words[i][j] == '0') continue;
            temp += defalut_dict[words[i][j]];
            temp *= 10;
        }
        temp /= 10;
        ans += temp;
    }
    cout << ans << endl;

    return 0;
}