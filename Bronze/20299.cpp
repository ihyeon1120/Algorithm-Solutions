// Problem: BOJ 

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

    int n, k, l; cin >> n >> k >> l;
    int ans = 0;
    vector<int> res;
    while(n--) {
        int x1, x2, x3; cin >> x1 >> x2 >> x3;
        if (x1 >= l && x2 >= l && x3 >= l && x1 + x2 + x3 >= k) {
            res.push_back(x1);
            res.push_back(x2);
            res.push_back(x3);
            ans += 1;
        }
    }
    cout << ans << endl;
    for (int i : res) cout << i << " ";

    return 0;
}