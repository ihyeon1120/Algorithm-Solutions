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
    set<pll> s;
    int n, q; cin >> n >> q;
    ll black_len = 0;

    while(q--) {
        ll l, r;
        cin >> l >> r;

        ll L = l, R = r;

        auto it = s.lower_bound({L, -LLONG_MAX});
        // 왼쪽구간
        if (it != s.begin()) {
            auto it2 = prev(it);
            if (it2->second >= L - 1) {
                L = min(L, it2->first);
                R = max(R, it2->second);
                black_len -= (it2->second - it2->first + 1);
                it = s.erase(it2);
            }
        }
        // 오른쪽
        while (it != s.end() && it->first <= R + 1) {
            L = min(L, it->first);
            R = max(R, it->second);
            black_len -= (it->second - it->first + 1);
            // erase는 삭제하고 다음걸로 넘어감
            it = s.erase(it);
        }

        s.insert({L, R});
        black_len += (R - L + 1);

        cout << (n - black_len) << endl;
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