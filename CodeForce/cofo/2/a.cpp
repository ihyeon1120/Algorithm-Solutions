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

/*
    3 -> 1 1 1 -> 1
    4 -> 1 1 2 -> 1
    5 -> 1 1 3 -> 1 + 1 = 2
    6 -> 1 1 4 -> 1 + 1 = 2
    7 -> 1 1 5 -> 1 + 2 = 3
    8 -> 1 1 6 -> 1 + 2 = 3
    9 -> 1 1 7 -> 1 + 3 = 4
*/

void solve() {
    ll n; cin >> n;
    cout << (n-1)/2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc;
    while(tc--)
        solve();

    return 0;
}