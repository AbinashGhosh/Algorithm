#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#define D 8
using namespace std;
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight direction
struct S
{
    int row,col;
    S(int R,int C)
    {
        row=R;
        col=C;
    }
};
int d[100][100],R,C;
void BFS2D(int x,int y)
{
    int gc,gr;
    memset(d,-1,sizeof(d));
    queue<S>Q;
    Q.push(S(x,y));
    d[x][y]=0;
    while(!Q.empty())
    {
        S u=Q.front();
        Q.pop();
        for(int i=0; i<D; i++)
        {
            gr=u.row+dx[i];
            gc=u.col+dy[i];
            if(gr>=0&&gr<R&&gc>=0&&gc<C&&d[gr][gc]==-1)
            {
                Q.push(S(gr,gc));
                d[gr][gc]=d[u.row][u.col]+1;
            }
        }
    }
}
int main()
{
    int x,y,i,j;
    scanf("%d%d%d%d",&R,&C,&x,&y);
    BFS2D(x,y);
    for(i=0;i<R;++i){
        for(j=0;j<C;++j)
          printf("%2d ",d[i][j]);
        printf("\n");
    }
    return 0;
}
