#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Rect {
    ll x1, x2, y1, y2;
};

void solve() {
    int n; cin >> n;
    ll x, y; cin >> x >> y;
    vector<Rect> rects = {{0, x-1, 0, y-1}};
    for (int i = 0; i < n; ++i) {
        char type; cin >> type;
        ll a, b; cin >> a, b;
        if (type = 'X') {
            for (int j = 0; j < sz(rects); ++j) {
                Rect cur = rects[i];
                if (a < cur.x1 || cur.x2 > a) continue;
                
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}