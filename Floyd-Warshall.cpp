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
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
using namespace std;
int nodes,edgenum,d[101][101],par[101][101];
bool chk[101][101];
void FloydWarshall(int n)
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            if(i==j)d[i][j]=0,par[i][j]=-1;
            else if(chk[i][j]==false)
                d[i][j]=M,par[i][j]=-1;
        }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
               if(d[i][j]>d[i][k]+d[k][j])
               {
                   d[i][j]=d[i][k]+d[k][j];
                   par[i][j]=par[k][j];
               }
}
void path(int i,int j)
{
    if(par[i][j]==-1)
        printf("%d",j);
    else
    {
       path(i,par[i][j]);
       printf("-%d",j);
    }
}
int main()
{
    READ("Floyd-Warshall.txt");
    int n1,n2,cost,str,end;
    scanf("%d%d",&nodes,&edgenum);
    mem(chk,false);
    for(int i=1;i<=edgenum;++i)
    {
        scanf("%d%d%d",&n1,&n2,&cost);
        d[n1][n2]=cost;
        par[n1][n2]=n1;
        chk[n1][n2]=true;
    }
    FloydWarshall(nodes);
   /* for(int i=1;i<=nodes;++i)
    {
        for(int j=1;j<=nodes;++j)
            printf("%2d ",d[i][j]);
        printf("         ");
        for(int j=1;j<=nodes;++j)
            printf("%2d ",par[i][j]);
        printf("\n");
    }*/
    while(scanf("%d%d",&str,&end)==2)
    {
       path(str,end);
       printf("\n");
    }
    return 0;
}

