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

    ll n, s; cin >> n >> s;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    vector<ll> prefix(n+1, 0);
    for (int i = 1; i < n + 1; ++i) {
        prefix[i] = prefix[i-1] + v[i-1];
    }
    if (prefix[n] < s) {
        cout << 0 << endl;
        return 0;
    }
    int lo = 1;
    int hi = n;
    int ans = n + 1;
    while (lo <= hi) {
        int m = (lo + hi) / 2;
        bool flag = false;
        for (int i = 0; i < n - m + 1; ++i) {
            ll sum = prefix[i + m] - prefix[i];
            if (sum >= s) {
                flag = true; 
                break;
            }
        }
        if (flag) {
            ans = m;
            hi = m - 1;
        }
        else lo = m + 1;
    }
    cout << ans << endl;

    return 0;
}