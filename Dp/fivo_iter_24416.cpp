// Problem: BOJ 24416

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll ans1 = 0;
ll ans2 = 0;

int fivo_recur(int n) {
    if (n == 1 || n == 2) {
        ans1 ++;
        return 1;
    } else {
        return fivo_recur(n-1) + fivo_recur(n-2);
    }
}

int fivo_iter(int n) {
    vector<int> fivo(n+1);
    fivo[0] = 0;
    fivo[1] = 1;
    fivo[2] = 1;
    for (int i = 3; i <= n; ++i) {
        fivo[i] = fivo[i-1] + fivo[i-2];
        ans2 ++;
    }
    return fivo[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;

    fivo_iter(n);
    fivo_recur(n);
    cout << ans1 << " " << ans2;

    return 0;
}