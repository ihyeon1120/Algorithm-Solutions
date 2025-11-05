// Problem: BOJ 2164

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

    // n < 50만
    int n; cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; ++i) q.push(i);
    while(sz(q) != 1){
        int c1 = q.front(); q.pop();
        int c2 = q.front(); q.pop();
        q.push(c2);
    }
    cout << q.front();

    return 0;
}