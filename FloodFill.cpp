#include<cstdio>
int dr[8]={-1,-1,-1, 0,+1,+1,+1, 0};
int dc[8]={-1, 0,+1,+1,+1, 0,-1,-1};
//4 direction
//int dr[8]={-1, 0,+1, 0};
//int dc[8]={ 0,+1, 0,-1};
char  seen[100][100];
bool visit[100][100];
void DFS_visit(int i,int j,int r,int c)
{
    int ir,ic;
    seen[i][j]='2';
    for(int k=0;k<8;++k)
    {
        ir=i+dr[k];
        ic=j+dc[k];
        if(ir>0&&ir<=r&&ic>0&&ic<=c&&seen[ir][ic]=='1')
            DFS_visit(ir,ic,r,c);
    }
}
int FloodFill(int r,int c)
{
    int ans=0;
    for(int i=1;i<=r;++i)
        for(int j=1;j<=c;++j)
            if(seen[i][j]=='1')
            {
                ans++;
                DFS_visit(i,j,r,c);
            }

    return ans;
}
int main()
{
    int r,c,i,j,ans;
    scanf("%d%d",&r,&c);
    for(i=1;i<=r;++i)
    {
        getchar();
        for(j=1;j<=c;++j)
           scanf("%c",&seen[i][j]);

    }
    ans=FloodFill(r,c);
    printf("%d\n",ans);
    return 0;
}

