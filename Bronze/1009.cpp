// Problem: BOJ 1009

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

    int t; cin >> t;
    while(t--) {
        ll a, b; cin >> a >> b;
        int k = 1;
        for (int i = 1; i <= b; ++ i) {
            k *= a;
            k = k % 10;
        }
        k = k == 0 ? 10 : k;
        cout << k << endl;
        
    }

    return 0;
}