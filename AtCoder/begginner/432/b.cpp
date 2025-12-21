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
    int n; cin >> n;
    vector<int> a;
    while(n > 0) {
        a.push_back(n % 10);
        n /= 10;
    }
    sort(all(a));
    for (int i = 0; i < sz(a); ++i) {
        if (a[i] != 0) {
            swap(a[0], a[i]);
        }
    }
    for (int i = 0; i < sz(a); ++i) cout << a[i] << "";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}