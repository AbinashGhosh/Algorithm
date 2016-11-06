#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#define  FOR(i, b, e) for(int i = b; i <= (int)(e); i++)
using namespace std;
char str1[25005],str2[25005];
int c[20005][20005],m,n;

int LCS()
{
    m=strlen(str1);
    n=strlen(str2);
    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0) c[i][j]=0;
            else
            {
                if(str1[i-1]==str2[j-1])
                   c[i][j]=c[i-1][j-1]+1;
                else
                   c[i][j]=max(c[i][j-1],c[i-1][j]);
            }
        }
   return c[m][n];
}
void pLCS(int i,int j)
{
    if (i==0 || j==0) return;
    if (str1[i-1]==str2[j-1])
    {
       pLCS(i-1,j-1);
       printf("%c",str1[i-1]);
    }
    else if (c[i][j]==c[i-1][j])
        pLCS(i-1,j);
    else
        pLCS(i,j-1);
}
// Memory Saving LCS O(n)
int d[25005],temp[25005];
int LCSm()
{
    m=strlen(str1);
    n=strlen(str2);
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0) temp[j]=0;
            else
            {
                if(str1[i-1]==str2[j-1])
                   temp[j]=d[j-1]+1;
                else
                   temp[j]=max(temp[j-1],d[j]);
            }
        }
        for(int j=0;j<=n;j++)d[j]=temp[j];
    }
   return d[n];
}
int main()
{
    //scanf("%s%s",str1,str2);
    FOR(i,0,20000)str1[i]=(rand()%11+rand()%17+rand()%31+rand()%7)%26+'a';str1[25001]='\0';
    FOR(i,0,20000)str2[i]=(rand()%29+rand()%19+rand()%13)%26+'a';str2[25001]='\0';
   // printf("%s \n\n\n %s",str1,str2);
    printf("%d ",LCS());
   // printf("%d ",LCSm());
    //pLCS(m,n);

    return 0;
}
