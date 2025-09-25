// Problem: BOJ 2720

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int Quarter = 25;
const int Dime = 10;
const int Nickel = 5;
const int Penni = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--)
    {
        int q = 0; int d = 0; int nk = 0; int p = 0;
        int n; cin >> n;
        while(n != 0) {
            if (n >= Quarter) {
                n -= Quarter;
                q ++;
            }
            else if (n >= Dime) {
                n -= Dime;
                d++;
            }
            else if (n >= Nickel) {
                n -= Nickel;
                nk++;
            }
            else if (n >= Penni) {
                n -= Penni;
                p++;
            }
        }
        cout << q << " " << d << " " << nk << " " << p << endl;
    }
    

    return 0;
}