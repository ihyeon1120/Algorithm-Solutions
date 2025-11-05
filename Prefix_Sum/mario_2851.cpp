// Problem: BOJ 2851

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

    int n = 10;
    int tg = 100;
    vector<int> pf(n+1, 0);
    for (int i = 0; i < n; ++i ){
        int t; cin >> t;
        pf[i+1] = pf[i]+ t;
    }
    int i = 1;
    for (; i < n+1; ++i) {
        if (pf[i] == tg) {
            break;
        }
        else if (pf[i] > tg) {
            if (1 < i && i < n+1) {
                if (abs(pf[i] - tg) > abs(pf[i-1] - tg)) {
                    i--;
                }
            }
            break;
        }
    }
    if (pf[10] < tg) i = 10;
    cout << pf[i] << endl;

    return 0;
}