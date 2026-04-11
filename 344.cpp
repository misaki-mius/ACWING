#include <bits/stdc++.h>
using namespace std;

// floyd find cycle??

const int INF = 1e8;
int N, M;
int dist[105][105], pa[105][105], E[105][105];
bool vis[105];

vector<int> ans;

void dfs(int i, int j){
    if (pa[i][j] == 0) return;
    dfs(i, pa[i][j]);
    ans.push_back(pa[i][j]);
    dfs(pa[i][j], j);
    
}

int main(){
    cin >> N >> M;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            dist[i][j] = INF;
            E[i][j] = INF;
        }
    }
    for (int i = 1; i <= M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
        E[u][v] = dist[u][v];
        E[v][u] = dist[v][u];
    }

    int minn = INF;
    for (int x = 1; x <= N; x++){
        for (int i = 1; i < x; i++){
            for (int j = i + 1; j < x; j++){
                if (dist[i][j] + E[i][x] + E[x][j] < minn){
                    minn = dist[i][j] + E[i][x] + E[x][j];
                    ans.clear();
                    ans.push_back(i);
                    dfs(i, j); // nodes between i and j
                    ans.push_back(j);
                    ans.push_back(x);
                }
            }
        }
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                if (dist[i][x] == INF || dist[x][j] == INF) continue;
                if (dist[i][j] > dist[i][x] + dist[x][j]){
                    dist[i][j] = dist[i][x] + dist[x][j];
                    pa[i][j] = x;
                }
            }
        }
    }
    if (minn == INF) cout << "No solution.";
    else for (int x : ans) cout << x << ' ';

    return 0;
}

