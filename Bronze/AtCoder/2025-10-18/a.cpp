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

    int s, a, b, x; cin >> s >> a >> b >> x;
    int ans = 0;
    ans = (x / (a + b)) * (s * a);
    int mod = (x % (a + b));
    if (mod > a) ans += a * s;
    else ans += mod * s;
    cout << ans << endl;
    return 0;
}