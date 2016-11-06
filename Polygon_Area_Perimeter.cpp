#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <utility>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define READ(f) freopen(f, "r", stdin)
using namespace std;

typedef pair<int, int> pii;
/*
   p[] holds the points, must be either in clockwise or counter clockwise
   function returns of an n -sided polygon.
*/
double pArea(vector<pii> p)
{
    int area=0,n=p.size();
    for(int i=0;i<n;++i)
        area+= p[i].x * p[(i+1)%n].y - p[i].y * p[(i+1)%n].x;
    return fabs(area/2.0);
}
double pPerimeter(vector<pii> p)
{
    double result=0,dx,dy;
    int n=p.size();
    for(int i=0;i<n;++i)
    {
        dx= p[(i+1)%n].x - p[i].x;
        dy= p[(i+1)%n].y - p[i].y;
        result+=sqrt(dx*dx+dy*dy);
    }
    return result;
}
int main()
{
    //READ("in.txt");
    int point,x,y;
    vector<pii>p;
    scanf("%d",&point);
    for(int i=1;i<=point;++i)
    {
        scanf("%d%d",&x,&y);
        p.pb(mp(x,y));
    }
    printf("%lf",pArea(p));
    return 0;
}
