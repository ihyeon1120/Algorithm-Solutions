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

    int a, b, c, d; cin >> a >> b >> c >> d;
    if (c >= a) {
        if (d >= b) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    else cout << "No" << endl;

    return 0;
}