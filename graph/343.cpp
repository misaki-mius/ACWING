#include <bits/stdc++.h>
using namespace std;

int N, M;

int main(){
    while (cin >> N >> M){
        if (N == 0 && M == 0) return 0;
        bool check[30][30];
        bool incons = 0, determined = 0;
        int cons_pos = 0;

        vector<int> E[30];
        vector<int> indeg(30, 0);

        string res = "";

        for (int i = 1; i <= 26; i++)
            for (int j = 1; j <= 26; j++)
                check[i][j] = 0;
        for (int i = 1; i <= M; i++){
            char a, b, dummy;
            cin >> a >> dummy >> b;
            if (incons || determined) continue;
            int u = a - 'A' + 1;
            int v = b - 'A' + 1;
            // cout << a << dummy << b << '\n';
            if (check[v][u]){
                incons = 1;
                cons_pos = i;
            }
            check[u][v] = 1;

            E[u].push_back(v);
            indeg[v]++;
            // topological sort
            vector<int> deg = indeg;
            queue<int> Q;
            for (int i = 1; i <= N; i++){
                if (deg[i] == 0) Q.push(i);
            }

            vector<int> ans;
            bool uni = 1;
            while (!Q.empty()){
                if (Q.size() > 1) uni = 0;
                int u = Q.front();
                Q.pop();
                ans.push_back(u);
                for (int v : E[u]){
                    deg[v]--;
                    if (deg[v] == 0) Q.push(v);
                }
            }
            if (ans.size() < N){
                incons = 1;
                cons_pos = i;
            } else if (uni) {
                determined = 1;
                cons_pos = i;
                for (int x : ans){
                    res += char('A' + x - 1);
                }
            }
        }
        
        // inconsistent
        if (incons){
            cout << "Inconsistency found after " << cons_pos << " relations.\n";
        } else if (determined){
            cout << "Sorted sequence determined after " << cons_pos << " relations: " << res << ".\n";
        } else {
            cout << "Sorted sequence cannot be determined.\n";
        }
        
        
        
    }
    


    return 0;
}