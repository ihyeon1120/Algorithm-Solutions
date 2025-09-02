// Problem: BOJ 12850

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;


const int MOD = 1000000007;
const int SZ = 8;


matrix operator*(const matrix &a, const matrix &b) {
    matrix ret(SZ, vector<ll>(SZ, 0));
    for (int i = 0; i < SZ; i++) {
        for (int j = 0; j < SZ; j++) {
            for (int k = 0; k < SZ; k++) {
                ret[i][j] += a[i][k] * b[k][j];
            }
            ret[i][j] = ret[i][j] % MOD;            
        }
    }
    return ret;
}

matrix power(const matrix &mat, ll D) {

    if (D == 1) return mat;

    matrix half = power(mat, D / 2);

    matrix result = half * half;

    if (D % 2 == 1) 
        result = result * mat;
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    matrix mat = 
    {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 1, 0, 0},
        {0, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 1, 1, 1},
        {0, 0, 1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 1, 0}
    };

    ll d; cin >> d;

    
    cout << power(mat, d)[SZ-1][SZ-1] % MOD << endl;

    return 0;
}