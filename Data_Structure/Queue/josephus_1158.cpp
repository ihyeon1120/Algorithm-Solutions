// Problem: BOJ 1158

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
    // n, k <= 5000 nk 가능
    int n, k; cin >> n >> k;
    k--;
    queue<int> q;
    for (int i = 0; i < n; ++i) q.push(i+1);
    cout << "<";
    while(sz(q) != 1) {
        for (int i = 0; i < k; ++i) {
            int t = q.front(); q.pop();
            q.push(t);
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">";
    return 0;
}