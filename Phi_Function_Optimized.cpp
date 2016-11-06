#include<cstdio>
#define M 1000005
int phi[M];
void calculate_phi()
{
    for(int i=1;i<M;++i)
        phi[i]=i;
    for(int p=2;p<M;++p)
        if(phi[p]==p)
           for(int k=p;k<M;k+=p)
              phi[k]-=phi[k]/p;
}
int main()
{
    calculate_phi();

    int N;
    int def=0;
    for(int i=1;i<=5000;i++)
        if(i%phi[i]==0)
        {
            printf("%d = %d %d\n",i,i%phi[i],i-def);
            def++;
        }
        printf("%d",def);
    return 0;
}
