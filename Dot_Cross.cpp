#include <cstdio>
#include <iostream>
#include <utility>
#define x first
#define y second
#define mp make_pair
#define READ(f) freopen(f, "r", stdin)
using namespace std;

typedef pair<int, int> pii;
//Compute the dot product of AB.BC
int dot(pii A,pii B,pii C)
{
    int dot=(B.x-A.x)*(C.x-B.x)+(B.y-A.y)*(C.y-B.y);
    return dot;
}
//Compute the cross product of AB x AC
int cross(pii A,pii B,pii C)
{
    int cross=(B.x-A.x)*(C.y-A.y)-(C.x-A.y)*(B.y-A.y);
    return cross;
}
inline int triArea(pii a,pii b,pii c)
{
	    return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}
int main()
{
    //READ("in.txt");
    pii a=mp(0,0),b=mp(0,2),c=mp(1,-16);
    double ans= cross(a,c,b);
    printf("%lf",ans);
    return 0;
}
