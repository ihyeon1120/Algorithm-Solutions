#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll count(ll n){
    return sqrtl(n); 
}

int main(){
    int t ; cin >> t;

    while(t--){
        ll c, d ; cin >> c >> d;
        ll ans = 0;

        ll L = stoll(to_string(c) + to_string(c + 1));
        ll R = stoll(to_string(c) + to_string(c + d)); 

        for(ll x = 1 ; ; x *= 10){
            ll currL = max(L , stoll(to_string(c) + to_string(x)));
            ll currR = min(R , stoll(to_string(c) + to_string(10LL * x - 1)));

            ll LR = max(0ll , count(currR) - count(currL - 1));
            ans += LR;

            if(currR >= R) break;
        }

        cout << ans << endl;
    }

    return 0;
}