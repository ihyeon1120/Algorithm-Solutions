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

void solve() {
    int t; cin >> t;
    while(t--) {
        int n, m, x, y; cin >> n >> m >> x >> y;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
        }
        for (int i = 0; i < m; i++) {
            int a; cin >> a;
        }
        cout << (n+1) * (m+1) / 2<< endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}