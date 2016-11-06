#include<cstdio>
#define INF 20000000
int L[32],S[32],I[32],LS[32],n;
void takeinput()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    scanf("%d",&S[i]);
}
int LISnlogn()
{
    I[0]=-INF;
    for(int i=1;i<=n;++i) I[i]=INF;
    int max=0;
    for(int i=0;i<n;++i)
    {
        int low=0,high=max,mid;
        while(low<=high)
        {
            mid= (low+high)/2;
            if(I[mid]<S[i])
               low=mid+1;
            else
               high=mid-1;
        }
        I[low]=S[i];
        L[i]=low;
        if(max<low) max=low;
    }
    return max;
}
void findSeq(int len)
{
    int i=0,top=len-1;
    for(int j=1;j<n;++j)
       if(L[j]>L[i])
          i=j;
    LS[top]=S[i];
    for(int j=i-1;j>=0;j--)
       if(S[j]<S[i]&&L[j]==L[i]-1)
       {
           i=j;
           top--;
           LS[top]=S[i];
       }
    for(int j=0;j<len;++j)
    printf("%d ",LS[j]);
}
int main()
{
    takeinput();
    int result=LISnlogn();
    printf("The LIS length is %d\n",result);
    findSeq(result);
    return 0;
}

