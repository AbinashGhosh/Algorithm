#include <cstring>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <list>
#include <set>
#include <utility>
#include <sstream>
#include<iomanip>

#define PI acos(-1.0)
#define MAX 10000007
#define M 1000
#define int64 long long
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define pb push_back
#define READ(f) freopen(f, "r", stdin)
using namespace std;

struct edge{
    int u,v,w;
    edge(int U,int V,int W){
        u=U,v=V,w=W;}
};
int nodes,source,edgenum,par[M],dis[M];
vector<edge>edges;
bool BellmanFord(int s)
{
    for(int i=1;i<=nodes;++i)
        dis[i]=MAX,par[i]=i;
    dis[s]=0;
    for(int i=1;i<=nodes-1;++i)
        for(int j=0;j<edges.size();++j)
        {
            edge e=edges[j];
            if(dis[e.v]>dis[e.u]+e.w)
            {
                dis[e.v]=dis[e.u]+e.w;
                par[e.v]=e.u;
            }
        }
    for(int j=0;j<edges.size();++j)
    {
        edge e=edges[j];
        if(dis[e.v]>dis[e.u]+e.w)
            return false;
    }
    return true;
}
int main()
{
    //READ("BellmanFord.txt");
    int u,v,w;
    scanf("%d%d%d",&nodes,&edgenum,&source);
    for(int i=0;i<edgenum;++i)
    {
        scanf("%d%d%d",&u,&v,&w);
        edges.pb(edge(u,v,w));
    }
    bool b=BellmanFord(source);
    if(b)
    {
        for(int i=1;i<=nodes;++i)
        {
           printf("%d ",dis[i]);
        }
        printf("\n");
    }
    else
        printf("No solution\n");

    return 0;
}
