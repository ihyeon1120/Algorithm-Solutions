// Problem: BOJ 1620

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

        map<string, string> pokemon;
    int n, m; cin >> n >> m;
    for (int i = 1; i < n + 1; ++i) {
        string s; cin >> s;
        pokemon[s] = to_string(i);
        pokemon[to_string(i)] = s;
    }
    while (m--) {
        string s; cin >> s;
        cout << pokemon[s] << endl;
    }

    return 0;
}