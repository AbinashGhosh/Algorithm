#include<iostream>
#include<vector>
#include<stack>
#include<cstdio>
#define MAX 10000
using namespace std;
int main()
{
    int node,edges,i,n1,n2,source,u,v;
    vector<int >edge[MAX];
    scanf("%d%d",&node,&edges);
    for(i=1;i<=edges;i++)
    {
        scanf("%d%d",&n1,&n2);
        edge[n1].push_back(n2);
        edge[n2].push_back(n1);
    }
    scanf("%d",&source);
    int taken[100]={0};
    taken[source]=1;
    stack<int>S;
    S.push(source);
    while(!S.empty())
    {
        u=S.top();
        printf("%d ",S.top());
        S.pop();
        for(i=0;i<edge[u].size();i++)
        {
            v=edge[u][i];
            if(!taken[v])
            {
                taken[v]=1;
                S.push(v);
            }
        }
    }
    return 0;
}
