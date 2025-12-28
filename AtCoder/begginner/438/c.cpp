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
    vector<int> s;

    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        s.push_back(t);

        int k = sz(s);
        if (k >= 4) {
            if (s[k-1] == s[k-2] && s[k-2] == s[k-3] && s[k-3] == s[k-4]) {
                s.pop_back();
                s.pop_back();
                s.pop_back();
                s.pop_back();
            }
        }
    }
    cout << sz(s) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}