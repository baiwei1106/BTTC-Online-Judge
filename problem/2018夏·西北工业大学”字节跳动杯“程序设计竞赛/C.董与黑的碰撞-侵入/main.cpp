#include <bits/stdc++.h>

using namespace std;

int indegree[1005];
int n, m, T, a, b;
vector <int> Map[1005];

int main()
{
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    fin>>T;
    int Case = 0;
    while (T--){
        int flag = 1;
        fin>>n>>m;
        for (int i=1; i<=n; i++){
            Map[i].clear();
        }
        memset(indegree,0,sizeof(indegree));
        for (int i=0; i<m; i++){
            fin>>a>>b;
            Map[a].push_back(b);
            indegree[b]++;
        }
        for (int i=0; i<n; i++){
            int pos = -1;
            for (int j=1; j<=n; j++){
                if (indegree[j] == 0){
                    pos = j;
                    break;
                }
            }
            if (pos == -1){
                flag = 0;
                break;
            }
            indegree[pos] = -1;
            for (int j=0; j<Map[pos].size(); j++) indegree[Map[pos][j]]--;
        }
        if (flag)
            fout<<"No Deadlock\n";
        else
            fout<<"Deadlock Occurs\n";
    }
    return 0;
}
