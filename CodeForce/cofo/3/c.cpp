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

#ifndef ONLINE_JUDGE
template<typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
    return os << "{" << p.first << ", " << p.second << "}";
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1) os << ", ";
    }
    return os << "]";
}

#define debug(...) cerr << "[DEBUG] " << #__VA_ARGS__ << ": ", DBG(__VA_ARGS__)
template<typename T> void DBG(const T& v) { cerr << v << endl; }
template<typename T, typename... Args> void DBG(const T& v, const Args&... args) { cerr << v << ", "; DBG(args...); }
#else
#define debug(...)
#endif


void solve() {
    ll n, m; cin >> n >> m;
    if (n > m || n*(n+1)/2 < m) {
        cout << -1 << endl;
        return;
    }
    // k(k-1)/2 + n <= m  ==> k^2 -k -2(m-n) <= 0인 k의 최대값
    ll k = (1 + sqrt(1 + 8*(m-n))) / 2;
    // 단말노드에 n-k개를 붙인다고 생각하고 시작
    ll s = (k*(k+1))/2 + (n - k);
    ll need = m - s;
    debug(m, s);

    cout << k << endl;; 
    for (int i = k; i > 1; --i) {
        cout << i << " " << i - 1 << endl;
    }

    for (int i = k+1; i <= n; ++i) {
        if (need >= k - 1) {
            cout << k << " " << i << endl;
            need -= (k-1);
        }
        else if (need > 0) {
            cout << (need + 1) << " " << i << endl;
            need = 0;
        }
        else {
            cout << 1 << " " << i << endl;
        }
        
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc;
    while(tc--) 
        solve();

    return 0;
}