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


int N, M;
int P[1005], V[1005];
ll suff[1005][50005];

void solve() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> P[i] >> V[i];
    }

    for (int w = 0; w <= M; w++) suff[N + 1][w] = 0;

    for (int i = N; i >= 1; i--) {
        for (int w = 0; w <= M; w++) {
            suff[i][w] = suff[i + 1][w];
            if (w >= P[i]) {
                suff[i][w] = max(suff[i][w], suff[i + 1][w - P[i]] + V[i]);
            }
        }
    }

    ll total_max = suff[1][M];
    vector<ll> pref(M + 1, 0);

    for (int i = 1; i <= N; i++) {
        ll val_in = -1;
        ll val_out = -1;

        for (int w = 0; w <= M; w++) {
            val_out = max(val_out, pref[w] + suff[i + 1][M - w]);
        }

        if (M >= P[i]) {
            ll temp_max = -1;
            for (int w = 0; w <= M - P[i]; w++) {
                temp_max = max(temp_max, pref[w] + suff[i + 1][M - P[i] - w]);
            }
            if (temp_max != -1) {
                val_in = V[i] + temp_max;
            }
        }

        if (val_in < total_max) {
            cout << "C" << "";
        } else {
            if (val_out == total_max) {
                cout << "B" << "";
            } else {
                cout << "A" << "";
            }
        }

        for (int w = M; w >= P[i]; w--) {
            pref[w] = max(pref[w], pref[w - P[i]] + V[i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}