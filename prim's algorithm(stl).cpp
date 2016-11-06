#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
#define SIZE 200005
int color[1000];
struct node
{
    int u,w;
    node(int i,int j){u=i;w=j;}
    bool operator<(const node& p)const
    {
        return w >p.w;    // Min Priority Queue
    }
};
vector<int>dist;
vector<node>edge[SIZE];
int Prims(int s,int nodes)
{
    priority_queue<node>Q;
    int i,sum,u;
    sum=0;
    Q.push(node(s,0));
    while(!Q.empty())
    {
        node top=Q.top();
        u=top.u;
        if(color[u]==0){
            sum+=top.w;
           // printf("%d %d\n",u,top.w);
        }
        color[u]=1;
        Q.pop();
        for(i=0; i<edge[u].size(); i++)
        {
            node v=edge[u][i];
            printf("%d %d\n",v.u,v.w);
            if(color[v.u]==0)
            {
                Q.push(v);
            }
        }
    }
    return sum;
}

int main()
{
    int nodes,edges,i,u,v,w,source,val;
    scanf("%d %d",&nodes,&edges);

        for(i=0; i<edges; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            node V(v,w);
           // printf("%d %d\n",V.u,V.w);
            edge[u].push_back(V);
            V.u=u; //For Bidirectional Edges
            edge[v].push_back(V);
        }
        val=Prims(1,nodes);
        printf("\n%d\n",val);
    return 0;
}
