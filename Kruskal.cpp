#include<cstdio>
#include<vector>
#include<algorithm>
#define M 100
using namespace std;
struct  edge{
    int u,v,w;
    bool operator <(const edge&p )const{
        return w<p.w;
    }
};
vector<edge>edges;
int parent[M];
int find_res(int r)
{
    return (parent[r]==r)?r:find_res(parent[r]);
}
int kruskal(int node)
{
    int i,u,v,s=0,count=0;
    sort(edges.begin(),edges.end());
    for(i=1;i<=node;++i)parent[i]=i;
    for(i=0;i<(int)edges.size();++i)
    {
        u=find_res(edges[i].u);
        v=find_res(edges[i].v);
        if(u!=v)
        {
            parent[u]=v;
            s+=edges[i].w;
            count++;
            if(count==node-1)break;
        }
    }
    return s;
}
int main()
{
    int node,edgenum,i,u,v,w,minimum;
    edge get;
    scanf("%d%d",&node,&edgenum);
    for(i=1;i<=edgenum;++i)
    {
        scanf("%d%d%d",&u,&v,&w);
        get.u=u,get.v=v,get.w=w;
        edges.push_back(get);
    }
    minimum=kruskal(node);
    printf("%d",minimum);
    return 0;
}
