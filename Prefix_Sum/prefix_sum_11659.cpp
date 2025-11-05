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
    
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i-1] + arr[i-1];
    }
    while (m--) {
        int i, j; cin >> i >> j;
        cout << prefix[j] - prefix[i-1] << endl;
    }

    return 0;
}