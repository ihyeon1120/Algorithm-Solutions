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


const int MAX_N = 500005;
const int OFFSET = 500005;
const int BIT_SIZE = 1000010; 

ll tree[BIT_SIZE];

void update(int idx, int val) {
    for (; idx < BIT_SIZE; idx += idx & -idx)
        tree[idx] += val;
}

ll query(int idx) {
    ll sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += tree[idx];
    return sum;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    ll ans = 0;
    int current_sum = 0;

    update(0 + OFFSET, 1);

    for (char c : s) {
        if (c == 'A') current_sum += 1;
        else if (c == 'B') current_sum -= 1;

        ans += query((current_sum + OFFSET) - 1);

        update(current_sum + OFFSET, 1);
    }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}