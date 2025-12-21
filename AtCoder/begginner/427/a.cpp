// Problem: A

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
    int l = sz(s);
    for (int i = 0; i < l; ++i) {
        if (i + 1 == (l + 1) / 2) continue;
        cout << s[i] << "";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}