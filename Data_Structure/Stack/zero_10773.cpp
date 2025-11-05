// Problem: BOJ 10773

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

    // k < 10만
    int k; cin >> k;
    vector<int> s;
    while(k--) {
        int t; cin >> t;
        if (t != 0) {
            s.push_back(t);
        } else {
            s.pop_back();
        }
    }

    ll ans = 0;
    for (int i : s) ans += i;
    cout << ans;

    return 0;
}