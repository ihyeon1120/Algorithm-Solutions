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

void solve() {
    int s, a, b, x; cin >> s >> a >> b >> x;
    int t = x / (a+b);
    int mod = x % (a + b);
    mod = (mod > a) ? a : mod;
    cout << a*s*t + mod*s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}