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

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int target_cnt = 0;
        vector<int> cnts(k, 0);
        for (int i = 0; i < n; ++i) {
            int t; cin >> t;
            if (t == k) target_cnt ++;
            else if (t < k) cnts[t] = 1;
        }
        int cnt = k - accumulate(all(cnts), 0);
        if (target_cnt >= cnt) cout << target_cnt << endl;
        else cout << cnt << endl;
    }

    return 0;
}