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

void solve() {
    vector<int> pf;
    int minus_cnt = 0;
    pf.push_back(0);
    int q; cin >> q;
    while(q--) {
        int type; cin >> type;
        if (type == 1) {
            char c; cin >> c;
            int t = (c == '(') ? 1 : -1;
            int p = pf.back() + t;
            if (p < 0) minus_cnt++;
            pf.push_back(p);
            if (p == 0 && minus_cnt == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else if (type == 2) {
            if (pf.back() < 0) minus_cnt--;
            pf.pop_back();
            if (pf.back() == 0 && minus_cnt == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}