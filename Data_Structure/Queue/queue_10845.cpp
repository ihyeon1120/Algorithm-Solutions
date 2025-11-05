// Problem: BOJ 10845

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

    queue<int> q;
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        if (s == "push") {
            int k; cin >> k;
            q.push(k);
        }
        else if (s == "front") {
            if(!q.empty()) cout << q.front() << endl;
            else cout << -1 << endl;
        }
        else if (s == "back") {
            if (!q.empty()) cout << q.back() << endl;
            else cout << -1 << endl;
        } 
        else if (s == "pop") {
            if (!q.empty()) {
                int n = q.front(); q.pop();
                cout << n << endl;
            }
            else {
                cout << -1 << endl;
            }
        }
        else if (s == "size") {
            cout << sz(q) << endl;
        }
        else if (s == "empty") {
            cout << q.empty() << endl;
        }
    }

    return 0;
}