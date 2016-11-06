#include<cstdio>
int main()
{
    int N,i,j,data[100],key;
    scanf("%d",&N);
    for(i=1;i<=N; i++)
        scanf("%d",&data[i]);

    for(j=2;j<=N;j++)
    {
        key= data[j];
        i=j-1;
        while(i>0&&data[i]>key)
        {
            data[i+1]=data[i];
            i--;
        }
        data[i+1]=key;
    }
    for(i=1;i<=N; i++)
        printf("%d ",data[i]);
    return 0;
}
