#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<utility>
#define mp make_pair
#define x first
#define y second
#define D 4
using namespace std;

typedef pair<int, int> pii;

int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight direction
int d[100][100],R,C;
void BFS2D(int x,int y)
{
    int gc,gr;
    memset(d,-1,sizeof(d));
    queue<pii>Q;
    Q.push(mp(x,y));
    d[x][y]=0;
    while(!Q.empty())
    {
        pii u=Q.front();
        Q.pop();
        for(int i=0; i<D; i++)
        {
            gr=u.x+dx[i];
            gc=u.y+dy[i];
            if(gr>=0&&gr<R&&gc>=0&&gc<C&&d[gr][gc]==-1)
            {
                Q.push(mp(gr,gc));
                d[gr][gc]=d[u.x][u.y]+1;
            }
        }
    }
}
int main()
{
    int x,y,i,j;
    scanf("%d%d",&R,&C);//2D Grid Size
    scanf("%d%d",&x,&y);//source position
    BFS2D(x,y);
    for(i=0;i<R;++i){
        for(j=0;j<C;++j)
          printf("%2d ",d[i][j]);
        printf("\n");
    }
    return 0;
}
