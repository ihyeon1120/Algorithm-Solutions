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
    int h, w, n; 
    cin >> h >> w >> n;
    
    vector<vector<int>> arr(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> arr[i][j];
        }
    }

    set<int> called;
    for(int i=0; i<n; ++i) {
        int t; cin >> t;
        called.insert(t);
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        int cnt = 0;
        for (int j = 0; j < w; ++j) {
            if (called.count(arr[i][j])) {
                cnt++;
            }
        }
        ans = max(ans, cnt);
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