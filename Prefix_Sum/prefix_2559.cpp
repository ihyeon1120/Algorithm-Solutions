// Problem: BOJ 2559

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

    int n, k; cin >> n >> k;
    vector<int> pre(n+1, 0);
    for (int i = 1; i < n + 1; ++i) {
        int t; cin >> t;
        pre[i] = pre[i-1] + t;
    }
    int ans = INT_MIN;
    for (int i = 0; i < n - k + 1; ++i) {
        ans = max(ans, pre[i+k] - pre[i]);
    }
    cout << ans << endl;    
    return 0;
}