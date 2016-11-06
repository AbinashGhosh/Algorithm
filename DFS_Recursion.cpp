#include<iostream>
#include<vector>
#include<stack>
#include<cstdio>
#define MAX 10000
using namespace std;
vector<int >edge[MAX];
int p[MAX],color[MAX],f[MAX],t,edges,d[MAX],node;
void DFS_VISIT(int u)
{
    t = t + 1;
    d[u] = t;//start time
    color[u] =1;
    for(int v=0; v<edge[u].size(); v++)   //edge[u] vector stores the graph
    {
        if(color[edge[u][v]] ==0)
        {
            p[edge[u][v]] = u;
            DFS_VISIT(edge[u][v]);
        }
    }
    color[u] =2;
    t = t + 1;
    f[u] = t -d[u];//finishing time
}
void DFS()
{
    for(int u=0; u<=node; u++)
    {
        color[u]=0;
        p[u]=-1; //parent array
    }
    t = 0;
    for(int u=1; u<=node; u++)
    {
        if(color[u] ==0)
        {
            DFS_VISIT(u);
        }
    }
}

int main()
{
    int i,n1,n2,source,u,v;
    scanf("%d%d",&node,&edges);
    for(i=1; i<=edges; i++)
    {
        scanf("%d%d",&n1,&n2);
        edge[n1].push_back(n2);
        edge[n2].push_back(n1);
    }
    scanf("%d",&source);

    return 0;
}
