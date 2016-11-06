#include<cstdio>
int main()
{
    int ptr,k,data[100],N,temp,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    scanf("%d",&data[i]);
    //main algorithm
    for(k=0;k<N-1;k++)
    {
        ptr=0;
        while(ptr<=N-k-1)
        {
            if(data[ptr]>data[ptr+1])
            {
                temp=data[ptr];
                data[ptr]=data[ptr+1];
                data[ptr+1]=temp;
            }
            ptr++;
        }
    }
    //algorithm ends
    for(i=0;i<N;i++)
    printf("%d ",data[i]);

    return 0;
}
