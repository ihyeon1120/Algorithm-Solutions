// Problem: BOJ 6086

#include <bits/stdc++.h>

#define endl "\n"
#define ends " "
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define MAX_SIZE 52
#define INF INT_MAX

int capacity[MAX_SIZE][MAX_SIZE] = {0}; 
int flow[MAX_SIZE][MAX_SIZE] = {0};

int ctoi(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    }
    return c - 'a' + 26;
}

int edmonds_karp(int source, int sink) {
    int total_flow = 0;
    while(1) {
        vector<int> parent(MAX_SIZE, -1);
        queue<int> q;
        parent[source] = source;
        q.push(source);
        // BFS 종료 조건에 + sink에 도착하면 종료
        while (!q.empty() && parent[sink] == -1)
        {
            int here = q.front(); q.pop();
            for(int there = 0; there < MAX_SIZE; there++) {
                if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
        // sink까지의 경로를 못 찾으면 break
        if (parent[sink] == -1) break;
        
        // 백트래킹을 통해서 증가 경로에서 잔여유량이 최소인 값을 amount에 저장
        int amount = INF;
        for(int p = sink; p != source; p = parent[p]) {
            // amout와 parent[p] -> p까지의 잔여유량 중 최소값
            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        }
        // 찾은 증가경로의 유량 증가, 역방향 유량 감소
        for(int p = sink; p != source; p = parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        total_flow += amount;
    }

    return total_flow;

}

void solve() {
    int n; cin >> n;
    while(n--) {
        char s_char, e_char; 
        int w;
        cin >> s_char >> e_char >> w;
        int s = ctoi(s_char);
        int e = ctoi(e_char);
        capacity[s][e] += w;
        capacity[e][s] += w;
    }

    int source = ctoi('A');
    int sink = ctoi('Z');
    cout << edmonds_karp(source, sink) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}