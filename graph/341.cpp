#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M;
int A[100005];
int maxn[100005], minn[100005]; // minn for 1~i, maxn for i~N
vector<int> E[100005], rE[100005];
bool vis[100005];

void get_min(){
    queue<int> Q;
    vector<bool> inq(N+1, 0);
    Q.push(1);
    minn[1] = A[1];

    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        inq[u] = 0;
        for (int v : E[u]){
            if (minn[v] > min(A[v], minn[u])){
                minn[v] =  min(A[v], minn[u]);
                if (!inq[v]){
                    Q.push(v);
                    inq[v] = 1;
                }
            }
        }
    }
}

void get_max(){
    queue<int> Q;
    vector<bool> inq(N+1, 0);
    Q.push(N);
    maxn[N] = A[N];

    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        inq[u] = 0;
        for (int v : rE[u]){
            if (maxn[v] < max(A[v], maxn[u])){
                maxn[v] =  max(A[v], maxn[u]);
                if (!inq[v]){
                    Q.push(v);
                    inq[v] = 1;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++){
        cin >> A[i];
        maxn[i] = -1, minn[i] = INF;
    }
    for (int i = 1; i <= M; i++){
        int u, v, z;
        cin >> u >> v >> z;
        E[u].push_back(v);
        rE[v].push_back(u);
        if (z == 2) E[v].push_back(u);
        if (z == 2) rE[u].push_back(v);
    }

    // update minn
    get_min();
    // for (int i = 1; i <= N; i++) cout << minn[i] << ' '; cout << '\n';

    // update maxn
    get_max();
    // for (int i = 1; i <= N; i++) cout << maxn[i] << ' '; cout << '\n';


    int ans = 0;
    for (int i = 1; i <= N; i++){
        if (minn[i] == INF || maxn[i] == -1) continue;
        ans = max(ans, maxn[i] - minn[i]);
    }
    cout << ans << '\n';
    return 0;
}