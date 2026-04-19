#include <bits/stdc++.h>
using namespace std;
#define int long long

int T, N;
int pa[6005], cnt[6005];
struct qwq{
    int u, v, w;
}E[6005];

int find(int x){
    if (pa[x] == x) return x;
    return pa[x] = find(pa[x]);
}

void merge(int x, int y){
    pa[find(x)] = pa[y];
}

bool cmp(qwq a, qwq b){
    return a.w < b.w;
}

void solve(){
    int ans = 0;
    cin >> N;
    for (int i = 1; i <= N; i++){
        pa[i] = i;
        cnt[i] = 1;
    }
    for (int i = 1; i < N; i++){
        int u, v, w;
        cin >> E[i].u >> E[i].v >> E[i].w;
    }
    sort(E+1, E+N, cmp);
    for (int i = 1; i < N; i++){
        auto[u, v, w] = E[i];
        int rootu = find(u);
        int rootv = find(v);
        if (rootu != rootv){
            ans += (cnt[rootu] * cnt[rootv] - 1) * (w + 1);
            pa[rootu] = rootv;
            cnt[rootv] += cnt[rootu];
        }
    }
    cout << ans << '\n';
}

int32_t main(){
    cin >> T;
    while (T--){
        solve();
    }

    return 0;
}