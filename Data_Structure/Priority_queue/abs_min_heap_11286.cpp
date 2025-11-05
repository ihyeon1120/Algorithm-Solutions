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

struct cmp{
    bool operator()(int a, int b){
        if (abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int> ,cmp> pq;

    int n; cin >> n;
    while(n--) {
        int k; cin >> k;
        if (k == 0) {
            if (pq.empty()) cout << 0 << endl;
            else {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
        else {
            pq.push(k);
        }
    }

    return 0;
}