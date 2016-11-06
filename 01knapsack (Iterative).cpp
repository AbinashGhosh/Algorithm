#include<cstdio>
#include<iostream>
using namespace std;
#define M 100
int N,capacity,fun[M][M],weight[M],cost[M];
int knapsack()
{
    for(int i=0;i<=N;i++)
        for(int j=0;j<=capacity;j++)
        {
            if(i==0||j==0)fun[i][j]=0;
            fun[i][j]=fun[i-1][j];
            if(j>=weight[i])
            fun[i][j]=max(fun[i][j],cost[i]+fun[i-1][j-weight[i]]);
        }
    return fun[N][capacity];
}
int main()
{
    int ans;
    scanf("%d%d",&N,&capacity);
    for(int i=1;i<=N;++i)
        scanf("%d%d",&cost[i],&weight[i]);
    ans= knapsack();
    printf("%d\n",ans);

    return 0;
}
/*
3 50
60 10
100 20
120 30
*/
