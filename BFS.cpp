#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#define MAX 10000
#define READ(f) freopen(f, "r", stdin)
using namespace std;
int d[100],par[100];
vector<int> edge[MAX];
void BFS(int node,int s)
{
    int color[100]= {0},u,v,i;
    color[s]=1;
    d[s]=0;
    par[s]=s;
    queue<int>Q;
    Q.push(s);
    while(!Q.empty())
    {
        u=Q.front();
        for(i=0;i<edge[u].size();i++)
        {
            v=edge[u][i];
            if(!color[v])
            {
                color[v]=1;
                d[v]=d[u]+1;
                par[v]=u;
                Q.push(v);
            }
        }
        Q.pop();
    }
}
int main()
{
    //READ("BFS.txt");
    int i,j,node,edges,n1,n2,s,u,v;
    scanf("%d%d%d",&node,&edges,&s);
    for(i=1; i<=edges; i++)
    {
        scanf("%d%d",&n1,&n2);
        edge[n1].push_back(n2);
        edge[n2].push_back(n1);
    }
    BFS(node,s);
    for(i=1;i<=node;++i)
        printf("%d = %d\n",i,d[i]);
    return 0;
}

