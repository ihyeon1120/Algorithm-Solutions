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
    vector<int> cards(n);
    for (int i = 0; i < n; ++i) cin >> cards[i];
    sort(all(cards), greater<>());
    int ans = 0;
    int turn = 1;
    for (int i = 0 ; i < n; ++i) {
        ans += cards[i] * turn;
        turn *= -1;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}