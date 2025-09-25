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

    ll a, b; cin >> a >> b;
    queue<ll> q;
    q.push(a);
    map<ll, int> visited;
    visited[a] = 1;
    int ans = -1;
    while(!q.empty()) {
        ll cur = q.front(); q.pop();
        if (cur == b) {
            ans = visited[b];
            break;
        }
        ll next = cur * 10 + 1;
        if (next <= b && visited[next] == 0) {
            q.push(next);
            visited[next] = visited[cur] + 1;
        }
        next = cur * 2;
        if (next <= b && visited[next] == 0) {
            q.push(next);
            visited[next] = visited[cur] + 1;
        }
    }
    cout << ans << endl;
    return 0;
}