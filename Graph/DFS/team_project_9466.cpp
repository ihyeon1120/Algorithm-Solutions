// Problem: BOJ 9466

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define MAX_SIZE 100001
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int visited[MAX_SIZE];
int student[MAX_SIZE];
int cycle_member;

void dfs(int i){
    // 상태가 2이면 이미 사이클 체크까지 전부 완료된 상태
    if(visited[i] == 2) return;

    // 상태가 1이면 이미 방문은 했지만 사이클 체크를 해야할 상태
    if(visited[i] == 1) {
        int cur = i;
        cycle_member ++;
        // 반복문으로 사이클이 발견된 노드부터 계속 다음노드로 넘어가면 사이클에 포함되는 인원수를 세어줌
        while (cur != student[i]) {
            cycle_member ++;
            i = student[i];
        }
        return;
    }
    // 처음은 방문을 1로 체킹
    visited[i] = 1;

    dfs(student[i]);
    
    // 다 끝난 후에는 방문을 2로 체킹
    visited[i] = 2;
}

void solve(){
    int n; cin >> n;
    student[0] = 0;
    visited[0] = 0;
    cycle_member = 0;
    for (int i = 1; i < n+1; i++) {
        cin >> student[i];
        visited[i] = 0;
    }
    for (int i = 1; i < n+1; i ++) {
        dfs(i);
    }

    cout << n - cycle_member << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}