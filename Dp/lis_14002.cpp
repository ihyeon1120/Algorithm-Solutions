// Problem: BOJ 14002

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

    int n; cin >> n;
    vector<int> arr(n);
    vector<int> dp(n, 1);
    vector<int> parent(n, -1);
    for (int i = 0; i < n ; ++i) cin >> arr[i];

    for (int i = 0 ; i < n ; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                if (dp[i] < dp[j] + 1) parent[i] = j;
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int max_idx = 0;
    int t = dp[0];
    for (int i = 1; i < n; ++i) {
        if (t < dp[i]){
            t = dp[i];
            max_idx = i;
        }
    }
    cout << t << endl;
    vector<int> ans;
    for (int i = max_idx; i != -1; i = parent[i]) {
        ans.push_back(arr[i]);
    }
    reverse(all(ans));
    for (int i : ans) cout << i << " ";
    return 0;
}