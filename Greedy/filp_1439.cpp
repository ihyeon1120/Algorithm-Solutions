// Problem: BOJ 1439

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

    int ans[2] = {0, 0};
    string s; cin >> s;
    int n = s.length();
    int pre = s[0] - '0';
    ans[pre]++;
    for (int i = 1; i < n; ++i) {
        int cur = s[i] - '0';
        if (pre != cur) ans[cur]++;
        pre = cur;
    }
    cout << min(ans[0], ans[1]) << endl;
    return 0;
}