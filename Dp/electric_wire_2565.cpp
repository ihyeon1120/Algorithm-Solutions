// Problem: BOJ 2565

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool cmp(pii a, pii b) {
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<pii> arr(n);
    for (int i = 0; i < n; ++i) {
        int s, e; cin >> s >> e;
        arr[i] = {s, e};
    }
    sort(all(arr), cmp);
    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i].second > arr[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int max_val = *max_element(all(dp));
    cout << n - max_val << endl;

    return 0;
}