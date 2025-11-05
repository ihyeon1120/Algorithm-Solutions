#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <chrono>
#include <queue>
#include <deque>
#include <string>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <complex>
#include <bitset>    
#include <cstring>
#include <random>
using namespace std;  
#define ll long long 



void solve() {
    ll Sol = 0, N, A, B;
    cin >> N >> A >> B;
    string s;
    cin >> s;
    vector<int> PfA(N+1), PfB(N+1);
    for (int i = 0; i < N; i++) {
        if (s[i] == 'a') {PfA[i+1] = PfA[i] + 1; PfB[i+1] = PfB[i];}
        else {PfB[i+1] = PfB[i] + 1; PfA[i+1] = PfA[i];}
    }
    for (int i = 0; i < N; i++) {
        int ind1 = lower_bound(PfA.begin(), PfA.end(), PfA[i] + A) - PfA.begin();
        int ind2 = upper_bound(PfB.begin(), PfB.end(), PfB[i] + B-1) - PfB.begin();
        Sol += max(ind2-ind1, 0);
    }
    cout << Sol << '\n';

}

int main()   
{  
    cin.tie(nullptr); 
    ios_base::sync_with_stdio(false);     
    int Tc = 1;
    //cin >> Tc; 
    for (int T = 0; T < Tc; T++) solve();
}    
