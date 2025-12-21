    #include <bits/stdc++.h>

    #define endl "\n"
    #define sz(x) (int)(x).size()

    using namespace std;

    typedef long long ll;

    ll powerOf10[12]; 

    void solve() {
        int n; 
        ll m; 
        cin >> n >> m;
        
        vector<ll> arr(n);
        map<ll, int> mods[11]; 

        powerOf10[0] = 1;
        for(int i=1; i<=10; i++){
            powerOf10[i] = (powerOf10[i-1] * 10) % m;
        }

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            
            string s = to_string(arr[i]);
            int len = s.length();
            
            mods[len][arr[i] % m]++;
        }
        
        ll ans = 0;
        
        for (int i = 0; i < n; ++i) {
            ll x = arr[i];
            
            for (int len = 1; len <= 10; ++len) {

                ll current_val = (x % m * powerOf10[len]) % m;
                ll needed_rem = (m - current_val) % m;
                
                if (mods[len].count(needed_rem)) {
                    ans += mods[len][needed_rem];
                }
            }

        }
        
        cout << ans << endl;
    }

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        solve();
        return 0;
    }