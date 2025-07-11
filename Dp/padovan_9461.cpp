// Problem: BOJ 9461

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll pado[101];

void padovan() {
    pado[1] = 1; pado[2] = 1; pado[3] = 1;
    pado[4] = 2; pado[5] = 2;
    for (int i = 6; i < 101; i++) {
        pado[i] = pado[i-1] + pado[i-5];
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    padovan();
    int n; cin >> n;
    while(n--) {
        int i; cin >> i;
        cout << pado[i] << endl;
    }
    return 0;
}