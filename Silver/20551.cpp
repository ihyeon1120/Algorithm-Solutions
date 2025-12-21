// Problem: BOJ 20551

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
    int n, m; cin >> n >> m;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(all(arr));
    unordered_map<ll, ll> um;
    um.insert({arr[0], 0});
    ll prev = arr[0];
    for (int i = 1; i < n; ++i) {
        if (prev != arr[i]) {
            prev = arr[i];
            um.insert({arr[i], i});
        }
    }
    while (m--) {
        ll t; cin >> t;
        if (um.count(t)) cout << um[t] << endl;
        else cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}