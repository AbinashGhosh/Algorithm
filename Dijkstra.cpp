#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define MAX 100002
using namespace std;
vector<int> edge[MAX],cost[MAX];
int d[MAX],par[MAX];
struct node{
    int u,w;
    node(int a,int b){
        u=a,w=b;
    }
    bool operator<(const node &p)const{
        return w>p.w;
    }
};
void dijkstra(int s)
{
    memset(par,-1,sizeof(par));
    memset(d,63,sizeof(d));
    d[s]=0;
    priority_queue<node>Q;
    Q.push(node(s,0));
    while(!Q.empty())
    {
        node top=Q.top();Q.pop();
        int u=top.u;
        for(int i=0;i<(int)edge[u].size();++i)
        {
            int v=edge[u][i];
            if(d[v]>d[u]+cost[u][i])
            {
               d[v]=d[u]+cost[u][i];
               par[v]=u;
               Q.push(node(v,d[v]));
            }
        }
    }
}
int main()
{
    int n,e,s,i,n1,n2,w;
    scanf("%d",&n);
    e=n-1;
    s=1;
    for(i=0;i<e;++i)
    {
       scanf("%d%d%d",&n1,&n2,&w);
       edge[n1].push_back(n2);
       edge[n2].push_back(n1);
       cost[n1].push_back(w);
       cost[n2].push_back(-w);
    }
    dijkstra(s);
    long long ans=0;
    for(i=1;i<=n;++i)
        ans+=d[i];
    printf("%lld",ans);
    return 0;
}



