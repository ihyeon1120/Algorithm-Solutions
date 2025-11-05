// Problem: BOJ 2003

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

    int n; ll m; cin >> n >> m;
    vector<ll> prefix(n+1, 0);
    for (int i = 1; i < n + 1; ++i) {
        int x; cin >> x;
        prefix[i] = prefix[i-1] + x;
    }
    int ans = 0;
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i + len < n + 1; ++i) {
            if (prefix[i + len] - prefix[i] == m) ans ++;
        } 
    }
    cout << ans << endl;

    return 0;
}