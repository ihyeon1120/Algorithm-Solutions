// Problem: BOJ 1946

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<int>> scores(n, vector<int>(2));
        for (int i = 0; i < n; ++i){
            cin >> scores[i][0] >> scores[i][1];
        }
        sort(all(scores));
        int m;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int a = scores[i][0]; int b = scores[i][1];
            if (a == 1) {
                ans ++;
                m = b;
                continue;
            }
            if (b <= m) {
                ans ++;
                m = b;
            }
        }
        cout << ans << endl;
    }

    return 0;
}