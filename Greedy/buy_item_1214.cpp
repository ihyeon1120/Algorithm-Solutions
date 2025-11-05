// Problem: BOJ 1214

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

    ll D, P, Q; cin >> D >> P >> Q;
    if (D % P == 0 || D % Q == 0) {
        cout << D << endl;
        return 0;
    }
    if (P > Q) swap(P, Q);
    ll np = 0;
    ll nq = (D / Q) + 1;
    ll ans = nq * Q;
    ll cur_cost = ans;
    while(nq > 0) { 
        nq -= 1;
        if ((D - nq * Q) % P == 0) {
            cout << D << endl;
            return 0;
        }
        else {
            np = (D - nq * Q) / P + 1;
            cur_cost = np * P + nq * Q;
        }
        // if (ans == cur_cost) break;
        ans = min(ans, cur_cost);
    }
    cout << ans << endl;

    return 0;
}