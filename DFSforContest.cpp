#include<cstdio>
#include<cstring>
#include<vector>
#define READ(f) freopen(f, "r", stdin)
using namespace std;

vector<int>edge[100];
int color[100],v;
void DFS_visit(int u)
{
    color[u]=1;
    for(int i=0;i<edge[u].size();++i)
    {
        v=edge[u][i];
        if(color[v]==0)
        {
            DFS_visit(v);
        }
    }
}
void DFS(int node)
{
    for(int i=1;i<=node;++i)
        if(color[i]==0)
           DFS_visit(i);
}
int main()
{
    //READ("DFS.txt");
    int nodes,edges,source,n1,n2;
    scanf("%d%d",&nodes,&edges);
    for(int i=0;i<edges;++i)
    {
        scanf("%d%d",&n1,&n2);
        edge[n1].push_back(n2);
        edge[n2].push_back(n1);
    }
    DFS(nodes);

    return 0;
}
