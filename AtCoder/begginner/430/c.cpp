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

    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    vector<int> prefixA(n+1, 0);
    vector<int> prefixB(n+1, 0);
    for (int i = 0; i < n; ++i) {
        prefixA[i+1] = prefixA[i] + (s[i] == 'a');
        prefixB[i+1] = prefixB[i] + (s[i] == 'b');
    }
    int ans = 0;
    int l = 1; int r = 1;
    while (r <= n) {
        int cnt_a = prefixA[r] - prefixA[l-1];
        int cnt_b = prefixB[r] - prefixB[l-1];
        if (cnt_a >= a && cnt_b < b) ans ++;
        else if (cnt_b >= b) {
            r--;
            l++;
            continue;
        }
        r++;
    }
    while (l <= n) {
        int cnt_a = prefixA[r] - prefixA[l-1];
        int cnt_b = prefixB[r] - prefixB[l-1];
        if (cnt_a >= a && cnt_b < b) ans ++;
        l++;
    }
    cout << ans << endl;

    return 0;
}