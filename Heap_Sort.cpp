#include<cstdio>
#include<iostream>
#define Left(i) 2*i
#define Right(i) ((2*i)+1)
using namespace std;
int heap_size,length,data[100];
void Max_Heapify(int i)
{
    int l,r,largest;
    l=Left(i);
    r=Right(i);
    if(l<=heap_size&&data[l]>data[i])
        largest=l;
    else
        largest=i;
    if(r<=heap_size&&data[r]>data[largest])
        largest=r;
    if(largest!=i)
    {
        swap(data[i],data[largest]);
        Max_Heapify(largest);
    }
}
void Build_Max_Heapify()
{
    int i;
    heap_size=length;
    for(i=length/2;i>=1;--i)
        Max_Heapify(i);
}
int main()
{
    int i;
    scanf("%d",&length);
    for(i=1; i<=length; i++)
        scanf("%d",&data[i]);
    Build_Max_Heapify();
    for(i=length;i>=2;--i)
    {
        swap(data[1],data[i]);
        heap_size=heap_size-1;
        Max_Heapify(1);
    }
    for(i=1; i<=length; i++)
        printf("%d ",data[i]);
    return 0;
}
