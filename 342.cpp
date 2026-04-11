#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int INF = 1e9;
const int OFFSET = 10005;

int T, R, P, S;
vector<PII> E[500005];

int dist[500005], dp[500005];

void dijkstra(){
    for (int i = 1; i <= T; i++) dist[i] = INF, dp[i] = 0;
    dist[S] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    pq.push({0, S});
    
    while (!pq.empty()){
        auto[d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto[v, w] : E[u]){
            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                dp[v] = dp[u] + 1;
                pq.push({dist[v], v});
            }
        }
    }
}

int main(){
    cin >> T >> R >> P >> S;
    for (int i = 1; i <= R; i++){
        int u, v, w;
        cin >> u >> v >> w;
        w += OFFSET;
        E[u].push_back({v, w});
        E[v].push_back({u, w});
    }
    for (int i = 1; i <= P; i++){
        int u, v, w;
        cin >> u >> v >> w;
        w += OFFSET;
        E[u].push_back({v, w});
    }
    dijkstra();
    for (int i = 1; i <= T; i++){
        if (dist[i] == INF) cout << "NO PATH\n";
        else cout << dist[i] - dp[i] * OFFSET << '\n';
    }

    return 0;
}