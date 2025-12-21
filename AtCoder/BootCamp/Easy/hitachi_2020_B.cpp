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
    int a, b, m; cin >> a >> b >> m;
    vector<ll> ref(a);
    vector<ll> wave(b);
    for (int i = 0; i < a; ++i) cin >> ref[i];
    for (int i = 0; i < b; ++i) cin >> wave[i];
    ll min_cost = *min_element(all(ref)) + *min_element(all(wave));
    while(m--) {
        int x, y, c; cin >> x >> y >> c;
        min_cost = min(min_cost, ref[x-1] + wave[y-1] - c);
    }
    cout << min_cost << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}