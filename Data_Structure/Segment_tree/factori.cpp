// Problem: BOJ 7578

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> a, tmp;
ll ans = 0;

ll merge_cnt(int s, int m, int e) {
    int i = s, j = m + 1, k = s;
    ll ret = 0;
    while (i <= m && j <= e) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else {
            tmp[k++] = a[j++];
            ret += (m - i + 1);
        }
    }
    while (i <= m) tmp[k++] = a[i++];
    while (j <= e) tmp[k++] = a[j++];
    for (int t = s; t <= e; ++t) a[t] = tmp[t];
    return ret;
}

void divide (int s, int e) {
    int m;
    if (s < e) {
        m = (s + e) / 2;
        divide(s, m);
        divide(m+1, e);
        ans += merge_cnt(s, m, e);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    unordered_map<int, int> m;
    tmp = vector<int>(n);
    a = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        int t; cin >> t; 
        m.insert({t, i});
    }
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        a[i] = m[t];
    }
    
    divide(0, n-1);
    
    cout << ans << endl;

    return 0;
}