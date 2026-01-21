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

    int n, m; cin >> n >> m;
    priority_queue<ll> pqa;
    priority_queue<ll> pqb;
    for (int i = 0; i < n; ++i) {
        ll t; cin >> t; pqa.push(t);
    }

    for (int i = 0; i < m; ++i) {
        ll t; cin >> t; pqb.push(t);
    }

    while(!pqa.empty() && !pqb.empty()) {
        ll a = pqa.top();
        ll b = pqb.top(); pqb.pop();
        if (a < b) {
            b -= a;
            pqb.push(b);
        }
        if (pqb.empty()) {
            cout << "Alice" << endl;
            return;
        }

        a = pqa.top(); pqa.pop();
        b = pqb.top(); 
        if (b < a) {
            a -= b;
            pqa.push(a);
        }
        if (pqa.empty()) {
            cout << "Bob" << endl;
            return;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc;
    while(tc--)
        solve();

    return 0;
}