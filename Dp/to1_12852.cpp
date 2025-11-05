// Problem: BOJ 12852

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

    int x; cin >> x;
    vector<int> parent(x+1, 0);
    queue<int> q;
    vector<int> v(x+1, -1);
    q.push(x);
    v[x] = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur % 3 == 0) {
            int next = cur / 3;
            if (v[next] == -1) {
                q.push(next);
                v[next] = v[cur] + 1;
                parent[next] = cur;
            }
        }
        if (cur % 2 == 0) {
            int next = cur / 2;
            if (v[next] == -1) {
                q.push(next);
                v[next] = v[cur] + 1;
                parent[next] = cur;
            }
        }
        if (cur - 1 > 0) {
            int next = cur - 1;
            if (v[next] == -1) {
                q.push(next);
                v[next] = v[cur] + 1;
                parent[next] = cur;
            }         
        }
    }
    cout << v[1] << endl;
    vector<int> ans;
    for (int p = 1; p != 0; p = parent[p]) {
        ans.push_back(p);
    }
    reverse(all(ans));
    for (int i : ans) cout << i << " ";
    return 0;
}