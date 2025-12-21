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
    int n, l, r; cin >> n >> l >> r;
    vector<ll> a(n, 1);
    for (int i = 1; i < n; ++i){
        a[i] = a[i-1] * 2;
    }
    int xor_sum = 0;
    for (int i = l-1; i < r-1; ++i) {
        xor_sum ^= a[i];
    }   
    a[r] = xor_sum;
    for (ll i : a) cout << i << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    while(tc--)
        solve();

    return 0;
}