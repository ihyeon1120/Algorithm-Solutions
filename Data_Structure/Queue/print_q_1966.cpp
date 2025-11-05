// Problem: BOJ 1966

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
// 진짜 개대충 짰네
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<int> arr;
        vector<int> arr1;
        for (int i = 0; i < n; ++i) {
            int k; cin >> k;
            arr.push_back(k);
            arr1.push_back(k);
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) q.push(i);
        sort(all(arr1));
        int max_val = arr1[sz(arr1)-1];
        int ans = 0;
        while (true) {
            int t = q.front(); q.pop();
            if (arr[t] == max_val) {
                ans ++;
                arr1.pop_back();
                if (sz(arr1) == 0) {
                    break;
                }
                max_val = arr1[sz(arr1)-1];
            }
            else {
                q.push(t);
                continue;
            }
            if (t == m) break;
        }
        cout << ans << endl;


    } 

    return 0;
}