#include<cstdio>
#include<algorithm>
using namespace std;
#define M 100
int N,capacity,fun[M][M],weight[M],cost[M];
int knapsack(int i,int w)
{
    int profit1,profit2;
    if(i==N+1) return 0;
    if(fun[i][w]!=0)return fun[i][w];
    if(w+weight[i]<=capacity)
        profit1=cost[i]+knapsack(i+1,w+weight[i]);
    else
        profit1=0;
    profit2=knapsack(i+1,w);
    fun[i][w]=max(profit1,profit2);
    return fun[i][w];
}
int main()
{
    int ans;
    scanf("%d%d",&N,&capacity);
    printf("\n\n");
    for(int i=1;i<=N;++i)
        scanf("%d%d",&cost[i],&weight[i]);
    ans= knapsack(1,0);
    printf("%d\n",ans);

    return 0;
}
