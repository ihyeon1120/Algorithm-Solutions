// Problem: BOJ 2217

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
    int ans = INT_MIN;
    vector<int> ropes(n);
    for (int i = 0; i < n; ++i) cin >> ropes[i];
    sort(all(ropes));

    for (int i = 0; i < n; ++i) {
        int k = n - i;
        ans = max(ans, ropes[i] * k);
    }

    cout << ans << endl;

    return 0;
}