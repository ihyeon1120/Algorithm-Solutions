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
    int s; cin >> s;
    int i = 1;
    unordered_set<ll> ss;
    while (ss.count(s) == 0) {
        ss.insert(s);
        if (s % 2 == 0) s /= 2;
        else s = 3 * s + 1;
        i++;
    }
    cout << i << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}