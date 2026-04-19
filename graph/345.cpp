#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e9;

int N, T, S, En;

struct node{
    int u, v, w;
}E[2005];

int dp[1005][1005];
// dp[k][v] = shortest dist to vertex v using exactly k edges

int bellman_ford(int S, int T){
    for (int i = 0; i <= N; i++){
        for (int j = 1; j <= T; j++){
            dp[i][j] = INF;
        }
    }
    dp[0][S] = 0;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= T; j++){
            auto[u, v, w] = E[j];
            dp[i][v] = min(dp[i][v], dp[i-1][u] + w);
            dp[i][u] = min(dp[i][u], dp[i-1][v] + w);
        }
    }
    return dp[T][N];
}


int32_t main(){
    
    cin >> N >> T >> S >> En;
    for (int i = 1; i <= T; i++){
        cin >> E[i].u >> E[i].v >> E[i].w;
    }
    cout << bellman_ford(S, En) << '\n';

    return 0;
}