#include<cstdio>
#define INF 1000000000
int p[100],m[100][100],s[100][100];
void MCM(int n)
{
    for(int i=1;i<=n;i++)
        m[i][i]=0;
    for(int l=2;l<=n;l++)
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            m[i][j]=INF;
            for(int k=i;k<j;k++)
            {
                int q= m[i][k]+ m[k+1][j]+ p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
}
void pOP(int i,int j)
{
    if(i==j) printf("A%d",i);
    else
    {
        printf("(");
        pOP(i,s[i][j]);
        pOP(s[i][j]+1,j);
        printf(")");
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<=N;i++)
       scanf("%d",&p[i]);
    MCM(N);
    pOP(1,N);
//print the Multiplication table
//    for(int i=1;i<N;i++)
//    {
//        printf("\n");
//        for(int j=i;j<N;j++)
//            printf("%5d ",m[i][j]);
//    }

    return 0;
}
