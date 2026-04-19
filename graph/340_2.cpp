#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
typedef pair<int, int> PII;

int N, P, K;
vector<PII> E[1000005];

priority_queue<PII, vector<PII>, greater<PII> > pq;
int dist[1000005];

void dijkstra(){
    for (int i = 1; i <= (K+1) * N; i++) dist[i] = INF;
    dist[1] = 0;

    pq.push({0, 1});
    while (!pq.empty()){
        auto[d, u] = pq.top();
        // cout << u << '\n';
        pq.pop();
        if (d > dist[u]) continue;
        for (auto[v, w] : E[u]){
            // cout << v << '\n';
            int x = max(w, dist[u]); // new edge weight (maxmin)
            if (dist[v] > x){
                dist[v] = x;
                pq.push({x, v});
            }
        }
    }
}

int main(){
    cin >> N >> P >> K;
    for (int i = 1; i <= P; i++){
        int u, v, w;
        cin >> u >> v >> w;
        // layer 1
        E[u].push_back({v, w});
        E[v].push_back({u, w});
        for (int j = 1; j <= K; j++){ // total 2 ~ K + 1 layers
            int u1 = u + (j-1) * N; // node u in layer j
            int v1 = v + (j-1) * N; // node v in layer j
            int u2 = u + j * N; // node u in layer j+1
            int v2 = v + j * N; // node v in layer j+1
            
            // build edge between layer j and j+1
            // can only go from level j to level j + 1 therefore no backward path
            E[u1].push_back({v2, 0});
            E[v1].push_back({u2, 0});

            // build edge within layer j+1
            E[u2].push_back({v2, w});
            E[v2].push_back({u2, w});
        }
    }
    for (int i = 1; i <= K; i++){
        int u = i * N;
        int v = (i + 1) * N;
        // end of level i to end of level i+1 -> prevent using less than k edges to get to end point
        E[u].push_back({v, 0});
    }
    // for (int i = 1; i <= (K+1) * N; i++){
    //     cout << i << ": ";
    //     for (auto[u, w] : E[i]){
    //         cout << u << ' ';
    //     }
    //     cout << '\n';
    // }
    dijkstra();
    if (dist[(K+1) * N] != INF) cout << dist[(K+1) * N];
    else cout << -1;
    


    return 0;
}