#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve() {
    int n; cin >> n;
    priority_queue<double, vector<double>, greater<double>> pq;
    for (int i = 0 ; i< n; ++i){
        double t; cin >> t;
        pq.push(t);
    }

    for (int i = 0; i < n-1; ++i) {
        double x = pq.top(); pq.pop();
        double y = pq.top(); pq.pop();
        pq.push((x + y) / 2.0);
    }
    cout << pq.top() << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int tc; cin >> tc;
    //while(tc--)
    solve();

    return 0;
}