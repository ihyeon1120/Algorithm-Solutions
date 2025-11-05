// Problem: BOJ 11000

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
    vector<pll> times(n);
    for (int i = 0; i < n; ++i) {
        ll s, e; cin >> s >> e;
        times[i] = {s, e};
    }
    sort(all(times));
    priority_queue<ll, vector<ll>, greater<>> pq;
    pq.push(times[0].second);
    for (int i = 1; i < n; ++i) {
        if (times[i].first >= pq.top()) {
            pq.pop();
        }
        pq.push(times[i].second);
    }

    cout << sz(pq) << endl;



    return 0;
}