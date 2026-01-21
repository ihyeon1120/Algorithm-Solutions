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
    int l1, b1, l2, b2, l3, b3; cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    ll area = l1 * b1 + l2 * b2 + l3 * b3;
    ll t = sqrt(area);
    string ans;
    if (t * t != area) {
        cout << "No" << endl;
        return;
    }
    bool flag = false;
    if (l1 < b1) {
        swap(l1, b1); swap(l2, b2); swap(l3, b3);
    }
    if (l1 == t && l2 == t && l3 == t && b1 + b2 + b3 == t ) {
        flag = true;
    }
    if (l1 == t && l2 + l3 == t && b2 == b3 && b1 + b2 == t) {
        flag = true;
    }
    cout << (flag ? "Yes" : "No") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin >> tc;
    while(tc--) 
        solve();

    return 0;
}