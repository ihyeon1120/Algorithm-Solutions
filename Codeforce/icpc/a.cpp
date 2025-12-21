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
    int n, m; cin >> n >> m;
    vector<vector<ll>> letters(n, vector<ll>(26, 0));
    vector<ll> total(26, 0);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (char c : s) {
            letters[i][c - 'A'] ++;
            total[c - 'A'] ++;
        }
    }

    for (int i = 0; i < n; ++i) {
        ll k = LLONG_MAX;
        for (int c = 0; c < 26; ++c) {
            ll a = total[c] - letters[i][c];
            if (a == 0 && letters[i][c] > 0) {
                k = -1;
                break;
            }
            else if (a > 0) {
                if ((m * a - letters[i][c]) < 0) {k=-1;break;}
                k = min(k, (m * a - letters[i][c]) / a);
            }
        }
        k = (k < 0) ? -1 : k;
        cout << k << " ";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    //cout << (-1)/2 << endl;
    return 0;
}