// Problem: BOJ
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
    int n; cin >> n;
    int i, t;
    for (i = 1; i < n; ++i) {
        string s = to_string(i);
        t = 0;
        for (char c : s) {
            t += c - '0';
        }
        if (t + i == n) break;
    }
    cout << i;

    return 0;
}