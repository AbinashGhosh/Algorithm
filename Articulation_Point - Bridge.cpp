#include<cstdio>
#include<algorithm>
#include<vector>

#define READ(f) freopen(f, "r", stdin)
using namespace std;
/*
	edge[][]: undirected graph
	cut[w] is true if node w is an articulation point / cut-vertex
*/
#define MAX 1000
vector<int> edge[MAX];
int cut[MAX],vis[MAX],dis[MAX],low[MAX],time;
void AP(int u,int par=-1)
{
    int i,v,child=0;
    vis[u]=1;
    dis[u]=low[u]=++time;
    for(i=0;i<edge[u].size();++i){
        v=edge[u][i];
        if(v==par)continue;
        if(vis[v])
            low[u]=min(low[u],dis[v]);
        else{
            child++;
            AP(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dis[u])cut[u]=1;
        }
    }
    if(par==-1)cut[u]=(child>1);
}
/*
	edge[][]: undirected graph
	finds all the bridges in a connected graph and
	adds those edges to the Bridges[] vector
*/
vector< pair< int, int > > Bridges;
void Bridge(int u,int par)
{
    int i,v;
    vis[u]=1;
    dis[u]=low[u]=++time;
    for(i=0;i<edge[u].size();++i){
        v=edge[u][i];
        if(v==par)continue;
        if(vis[v])
            low[u]=min(low[u],dis[v]);
        else{
            Bridge(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dis[u])Bridges.push_back(make_pair(u, v));
        }
    }
}
int main()
{
    //READ("AP.txt");
    int i,node,edges,n1,n2,s;
    scanf("%d%d%d",&node,&edges,&s);
    for(i=1; i<=edges; i++)
    {
        scanf("%d%d",&n1,&n2);
        edge[n1].push_back(n2);
        edge[n2].push_back(n1);
    }
    AP(s);
    for(i=1; i<=node; ++i)
        if(cut[i]==1)
        printf("%d ",i);
    return 0;
}
