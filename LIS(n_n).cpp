#include<cstdio>
int L[32],S[32],LS[32],n;
void takeinput()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    scanf("%d",&S[i]);
}

int LIS()
{
    for(int i=0;i<n;++i) L[i]=1;// if declare L[] global no need this line and return max+1 :)
    int max=0;
    for(int i=0;i<n;++i)
    {
       for(int j=i+1;j<n;++j)
       {
           if(S[j]>S[i]&&L[j]<L[i]+1)
              L[j]=L[i]+1;
       }
       if(max<L[i]) max=L[i];
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
    int result=LIS();
    printf("The LIS length is %d\n",result);
    findSeq(result);
    return 0;
}
