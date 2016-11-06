#include<iostream>
#include<vector>
#include<cstdio>
#define MAX 10000
using namespace std;
int main()
{
    int i,j,node,edges,n1,n2,source,loop,u,v;
    vector<int> edge[MAX];
    vector<int> cost[MAX];
    scanf("%d%d",&node,&edges);
    int in[MAX]={0},out[MAX]={0};
    for(i=1;i<=edges;i++)
    {
        scanf("%d%d",&n1,&n2);
        edge[n1].push_back(n2);
        edge[n2].push_back(n1);
        cost[n1].push_back(n2);
        cost[n2].push_back(n1);
    }
    scanf("%d",&source);
    vector<int>V1,V2;
    int taken[100]={0};
    taken[source]=1;
    V1.push_back(source);
    printf("Level 0: %d\n",source);
    for(loop=1;loop<node;loop++)
    {
        printf("Level %d: ",loop);
        for(i=0;i<V1.size();i++)
        {
            u=V1[i];
            for(j=0;j<edge[u].size();j++)
            {
                v=edge[u][j];
                if(!taken[v])
                {
                    printf("%d ",v);
                    V2.push_back(v);
                    taken[v]=1;
                }
            }
        }
        if(V2.empty())
        {
            printf("Empty\n");
            break;
        }
        else
        {
            V1.clear();
            V1=V2;
            V2.clear();
            printf("\n");
        }

    }
    return 0;
}
