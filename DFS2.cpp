#include<cstdio>
#include<cstring>
#include<vector>
#define M 100
#define READ(f) freopen(f, "r", stdin)
using namespace std;

vector<int>edge[M];
int parent[M],color[M],v,d[M],f[M],time;
void DFS_visit(int u)
{
    color[u]=1;
    d[u]=++time;
    for(int i=0;i<edge[u].size();++i)
    {
        v=edge[u][i];
        if(color[v]==0)
        {
            parent[v]=u;
            DFS_visit(v);
        }
    }
    f[u]=++time;
}
void DFS(int node)
{
    for(int i=1;i<=node;++i)
        color[i]=0,parent[i]=0;
    time=0;
    for(int i=1;i<=node;++i)
        if(color[i]==0)
           DFS_visit(i);
}
int main()
{
    //READ("DFS.txt");
    int nodes,edges,source,n1,n2;
    scanf("%d%d%d",&nodes,&edges,&source);
    for(int i=0;i<edges;++i)
    {
        scanf("%d%d",&n1,&n2);
        edge[n1].push_back(n2);
        edge[n2].push_back(n1);
    }
    DFS(nodes);
    for(int i=1;i<=nodes;++i)
        printf("%2d / %2d\n",d[i],f[i]);

    return 0;
}
