#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;

#define  u first
#define  w second
#define  pb push_back
#define  mp make_pair
#define MAX 100002

typedef  pair <int, int> pii;


vector<int> edge[MAX],cost[MAX];
int d[MAX],par[MAX];


void dijkstra(int s)
{
    memset(par,-1,sizeof(par));
    memset(d,63,sizeof(d));
    d[s]=0;
    priority_queue<pii,vector<pii>,greater<pii > >Q;
    Q.push(mp(s,0));
    while(!Q.empty())
    {
        pii top=Q.top();Q.pop();
        int u=top.u;
        for(int i=0;i<(int)edge[u].size();++i)
        {
            int v=edge[u][i];
            if(d[v]>d[u]+cost[u][i])
            {
               d[v]=d[u]+cost[u][i];
               par[v]=u;
               Q.push(mp(v,d[v]));
            }
        }
    }
}
int main()
{
    int n,e,s,i,n1,n2,w;
    scanf("%d%d%d",&n,&e,&s);
    for(i=0;i<e;++i)
    {
       scanf("%d%d%d",&n1,&n2,&w);
       edge[n1].push_back(n2);
       edge[n2].push_back(n1);
       cost[n1].push_back(w);
       cost[n2].push_back(w);
    }
    dijkstra(s);
    for(i=0;i<=n;++i)
        printf("%d ",d[i]);
    return 0;
}



