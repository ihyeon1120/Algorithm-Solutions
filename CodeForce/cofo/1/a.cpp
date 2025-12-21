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
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        s.insert(t);
    }
    int prev = -1;
    while(prev != sz(s)) {
        prev = sz(s);
        s.insert(prev);
    }
    cout << prev << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    while(tc--)
        solve();

    return 0;
}