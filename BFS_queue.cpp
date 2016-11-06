#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#define MAX 10000
#define READ(f) freopen(f, "r", stdin)
using namespace std;
int main()
{
    int i,j,node,edges,n1,n2,source,loop,u,v,max;
    vector<int> edge[MAX],dis[MAX];
    vector<int> cost[MAX];
    scanf("%d%d",&node,&edges);
    //int in[MAX]={0},out[MAX]={0};
    for(i=1; i<=edges; i++)
    {
        scanf("%d%d",&n1,&n2);
        edge[n1].push_back(n2);
        edge[n2].push_back(n1);
        cost[n1].push_back(n2);
        cost[n2].push_back(n1);
    }
    scanf("%d",&source);
    max=1;
    queue<int>Q;
    Q.push(source);
    int taken[100]= {0},distance[100];
    taken[source]=1;
    distance[source]=0;
    dis[0].push_back(source);
    while(!Q.empty())
    {
        u=Q.front();
        for(i=0; i<edge[u].size(); i++)
        {
            v=edge[u][i];
            if(!taken[v])
            {
                Q.push(v);
                taken[v]=1;
                distance[v]=distance[u]+1;
                if(max<distance[v])max=distance[v];
                dis[distance[v]].push_back(v);
            }
        }
        Q.pop();
    }
    printf("Maximum Distance : %d\n",max);
    for(i=0; i<=max; i++)
    {
        printf("%d distance node are ",i);
        for(j=0; j<dis[i].size(); j++)
            printf("%d ",dis[i][j]);
        printf("\n");
    }
    return 0;
}
