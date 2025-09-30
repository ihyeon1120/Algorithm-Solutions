// Problem: BOJ 31216

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
    // N = 3000이기 때문에 
    vector<int> nums;
    int cnt = 0;
    int n = 2;
    while (cnt <= 30000) {
        bool flag = 1;
        for (int t = 2; t <= sqrt(n); ++t) {
            if (n % t == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            nums.push_back(n);
            cnt++;
        }
        n++;
    }

    int t; cin >> t;
    while(t--) {
        int i; cin >> i;
        int k = nums[i-1];
        cout << nums[k-1] << endl;
    } 

    return 0;
}