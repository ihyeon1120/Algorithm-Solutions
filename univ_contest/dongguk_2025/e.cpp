// Problem:  

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

    int r, c; cin >> r >> c;
    int k = r*c/4;
    vector<vector<int>> ans;
    
    for (int i = 0; i < r/2; ++i) {
        int s = i*(k/(r/2));
        vector<int> t;
        for (int j = 1; j <= k/(r/2); ++j) {
            t.push_back(s + j);
        }
        for (int j = k / (r/2); j >= 1; --j) {
            t.push_back(s + j);
        }
        ans.push_back(t);
    }

    for (int i = 0; i < r/2; ++i) {
        for (int t : ans[i]) cout << t << " ";
        cout << endl;
    }
    for (int i = (r/2) - 1; i >= 0; --i) {
        for (int t : ans[i]) cout << t << " ";
        cout << endl;
    }
    
    return 0;
}