#include<iostream>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

#define endl "\n"

int main() {
    int n; cin >> n;
    int t;
    priority_queue<int, vector<int>, greater<int>> a;
    priority_queue<int> b;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a.push(t);
    }
    for (int i = 0; i < n; i++) {
        cin >> t;
        b.push(t);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a.top() * b.top();
        a.pop(); b.pop();
    }

    cout << ans << endl;
}