#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
typedef pair<int, int> PII;

int N, P, K;
vector<PII> E[100005];

int maxn = -1;

bool check(int x){

    priority_queue<PII, vector<PII>, greater<PII> > pq;
    vector<int> dist(N + 1, INF);
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty()){
        auto[d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        
        for (auto[v, w] : E[u]){
            int cost = 0;
            if (w > x) cost = 1;
            if (dist[v] > dist[u] + cost){
                dist[v] = dist[u] + cost;
                pq.push({dist[v], v});
            }
        }
    }
    // cout << dist[N] << '\n';
    return dist[N] > K;
}

int main(){
    cin >> N >> P >> K;
    for (int i = 1; i <= P; i++){
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({v, w});
        E[v].push_back({u, w});
        maxn = max(maxn, w);
    }
    int l = 0, r = 1e6;
    while (l <= r){
        int mid = l + r >> 1;
        // cout << mid << ' ';
        if (check(mid)){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (l != 1e6 + 1) cout << l << '\n';
    else  cout << -1 << '\n';


    return 0;
}