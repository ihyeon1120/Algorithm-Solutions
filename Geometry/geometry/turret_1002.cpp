// Problem: BOJ 1002

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
    int x1, y1, r1; cin >> x1 >> y1 >> r1;
    int x2, y2, r2; cin >> x2 >> y2 >> r2;
    ll dist = (x1 - x2) * (x1- x2) + (y1 - y2) * (y1 - y2);
    ll rsum = (r1 + r2) * (r1 + r2);
    ll rdiff = (r1 - r2) * (r1 - r2);
    int ans = -1;
    // 원 일치
    if (dist == 0 && rdiff == 0) 
        ans = -1;
    // 외접, 내접
    else if (dist == rsum || dist == rdiff)
        ans = 1;
    else if (dist > rsum || dist < rdiff)
        ans = 0;
    else 
        ans = 2;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    while(tc--) solve();

    return 0;
}