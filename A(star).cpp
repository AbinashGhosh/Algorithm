#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define MAX 100002
using namespace std;
vector<int> edge[MAX],cost[MAX];
int d[MAX],par[MAX],h[MAX];
struct node{
    int u,w;
    node(int a,int b){
        u=a,w=b;
    }
    bool operator<(const node &p)const{
        return w>p.w;
    }
};

void Astar(int s,int des)
{
    memset(par,-1,sizeof(par));
    memset(d,63,sizeof(d));
    d[s]=0;
    priority_queue<node>Q;
    Q.push(node(s,h[s]));
    while(!Q.empty())
    {
        node top=Q.top();Q.pop();
        int u=top.u;
        if(u==des)break;
        for(int i=0;i<(int)edge[u].size();++i)
        {
            int v=edge[u][i];
            if(d[v]>d[u]+cost[u][i])
            {
               d[v]=d[u]+cost[u][i];
               par[v]=u;
               Q.push(node(v,d[v]+h[v]));
            }
        }
    }
}
void path(int w)
{
    if(par[w]!=-1)path(par[w]);
    printf("%d ",w);
}
int main()
{
    int n,e,s,i,n1,n2,w,des;
    scanf("%d%d%d%d",&n,&e,&s,&des);
    for(i=0;i<e;++i)
    {
       scanf("%d%d%d",&n1,&n2,&w);
       edge[n1].push_back(n2);
       edge[n2].push_back(n1);
       cost[n1].push_back(w);
       cost[n2].push_back(w);
    }
    //h(n)
    for(i=1;i<=n;++i)
        scanf("%d",&h[i]);
    Astar(s,des);
    path(des);
    printf("\n%d",d[des]);
    return 0;
}
/*
10 11 1 10
1 2 140
1 3 118
1 4 75
2 5 99
2 6 151
2 7 80
5 10 211
7 8 146
7 9 97
8 9 138
9 10 101

366
253
329
374
176
380
193
160
100
0
*/



