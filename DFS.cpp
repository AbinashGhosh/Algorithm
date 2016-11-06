#include<cstdio>
#include<cstring>
#define M 100
bool graph[M][M];
bool color[M],node;
int DFS(int u)
{
    color[u]=true;
    printf("%d ",u);
    for(int i=1;i<=node;++i)
        if(graph[u][i]==true&&color[i]==false)
            DFS(i);
}
int main()
{
    int edge,source,n1,n2;
    freopen("DFS.txt","r",stdin);
    scanf("%d%d%d",&node,&edge,&source);
    for(int i=0;i<edge;++i)
    {
        scanf("%d%d",&n1,&n2);
        graph[n1][n2]=true;
    }
    DFS(source);
    return 0;
}
