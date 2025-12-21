// Problem: C

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int msb_idx(unsigned long long x) {
    if (x == 0) return -1;
    int k = 0;
    while (x >> (k+1)) ++k;
    return k;
}

void solve() {
    unsigned long long a, b; 
    cin >> a >> b;
    if (a == b) {
        cout << 0 << endl;
        return;
    }
    int ai = msb_idx(a);
    int bi = msb_idx(b);
    if (bi > ai) {
        cout << -1 << "\n";
        return;
    }

    if (ai == bi) { // 한 번에 끝
        unsigned long long x = a ^ b;       // x < 2^ai ≤ a
        cout << 1 << "\n" << x << "\n";
        return;
    }

    // ai > bi : 두 번이면 항상 가능
    unsigned long long A  = (1ULL << (ai + 1)) - 1; 
    unsigned long long x1 = a ^ A;                 
    unsigned long long x2 = A ^ b;        

    cout << 2 << "\n" << x1 << " " << x2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc;
    while(tc--)
        solve();

    return 0;
}
