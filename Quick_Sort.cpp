#include<cstdio>
int data[100];
int Partition(int p,int r)
{
    int x,i,j,temp;
    x=data[r];
    i=p-1;
    for(j=p;j<=r-1;j++)
    {
        if(data[j]<=x)
        {
            i++;
            temp=data[i];
            data[i]=data[j];
            data[j]=temp;
        }
    }
    temp=data[i+1];
    data[i+1]=data[r];
    data[r]=temp;
    return (i+1);
}
void Quicksort(int p,int r)
{
    int q;
    if(p<r)
    {
        q=Partition(p,r);
        Quicksort(p,q-1);
        Quicksort(q+1,r);
    }
}
int main()
{
    int i,N;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
        scanf("%d",&data[i]);
    Quicksort(1,N);
    for(i=1;i<=N;i++)
        printf("%d ",data[i]);
    return 0;
}
