#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define READ(f) freopen(f, "r", stdin)
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

//Compute the cross product of AB x AC
inline int cross(pii A,pii B,pii C)
{
    return ((B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y));
}
//return Is point k on the segment i to j
inline bool onsegment(pii i,pii j,pii k)
{
    return (min(i.x,j.x)<=k.x&&k.x<=max(i.x,j.x)&&min(i.y,j.y)<=k.y&&k.y<=max(i.y,j.y));
}
//compute two segment ab and cd intersect or not
bool LSI(pii a,pii b,pii c,pii d)
{
    int d1=cross(c,a,d);
    int d2=cross(c,b,d);
    int d3=cross(a,c,b);
    int d4=cross(a,d,b);
    if(((d1>0&&d2<0)||(d1<0&&d2>0))&&((d3>0&&d4<0)||(d3<0&&d4>0)))
        return true;
    if(!d1&&onsegment(c,d,a))return true;
    if(!d2&&onsegment(c,d,b))return true;
    if(!d3&&onsegment(a,b,c))return true;
    if(!d4&&onsegment(a,b,d))return true;
    return false;
}
int main()
{
    //READ("in.txt");
        int x,y,i;
    vpii p;
    for(i=1;i<=4;++i)
    {
        scanf("%d%d",&x,&y);
        p.pb(mp(x,y));
    }
    if(LSI(p[0],p[1],p[2],p[3]))
        printf("Intersect\n");

    return 0;
}

