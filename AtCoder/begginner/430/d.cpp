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

ll get_dist(map<ll, ll> &m, ll cur_pos ,ll prev_dist) {
    auto it = m.lower_bound(cur_pos);

    // it == begin이 되는 경우는 없음 제일 왼쪽 점은 0으로 고정
    if (it == m.end()) {
        ll left = prev(it) -> first;
        ll left_d = prev(it) -> second;
        ll cur_to_left = abs(cur_pos - left);
        if (cur_to_left < left_d || left_d == 0) {
            prev(it)-> second = cur_to_left;
            prev_dist += (cur_to_left - left_d);
        }
        prev_dist += cur_to_left;
        m[cur_pos] = cur_to_left;
        return prev_dist;
    }


    ll right = it->first;
    ll right_d = it->second;
    ll left = prev(it)->first;
    ll left_d = prev(it)->second;
    ll cur_to_left = abs(cur_pos - left);
    ll cur_to_right = abs(cur_pos - right);
    if (cur_to_left < left_d) {
        prev(it) -> second = cur_to_left;
        prev_dist += (cur_to_left - left_d);
    } 

    if (cur_to_right < right_d) {
        it->second = cur_to_right;
        prev_dist += (cur_to_right - right_d);
    }
    ll min_d =  min(cur_to_left, cur_to_right);
    prev_dist += min_d;
    m[cur_pos] = min_d;

    return prev_dist;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    map<ll, ll> house;
    house[0] = 0;
    ll d = 0;
    vector<ll> pos(N);
    for (int i = 0; i < N; ++i) cin >> pos[i];

    for (int t : pos) {
        d = get_dist(house, t, d);
        cout << d << endl;
    }

    return 0;
}