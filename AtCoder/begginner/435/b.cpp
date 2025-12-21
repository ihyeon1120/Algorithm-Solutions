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
    int ans = 0;
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i){ 
        int t; cin >> t;
        arr[i] = t;
    }
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            vector<int> sub(arr.begin() + i, arr.begin() + j + 1);
            ll sub_sum = accumulate(all(sub), 0);
            bool flag = true;
            for (int k : sub) {
                if (sub_sum % k == 0) {
                    flag = false;
                }
            }
            if (flag) ans ++;
        }
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