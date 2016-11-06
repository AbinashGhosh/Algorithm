#include <cstdio>
#include <cmath>
#include <vector>
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

//Compute the distance from A to B
double Distance(pii A,pii B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

//Compute the distance from AB to C
//it isSegment is true , AB is a line segment ,not a line.
double lpd(pii A,pii B,pii C,bool isSegment)
{
    double dist=cross(A,B,C)/Distance(A,B);
    if(isSegment)
    {
        int dot1=dot(A,B,C);
        if(dot1>0)return Distance(B,C);
        int dot2=dot(B,A,C);
        if(dot2>0)return Distance(A,C);
    }
    return fabs(dist);
}

int main()
{
    //READ("in.txt");
    pii a[3];
    int c,b;
    for(int i=0; i<=2; i++)
    {
        scanf("%d%d",&c,&b);
        a[i]=mp(c,b);
    }
    printf("%.0lf",lpd(a[0],a[1],a[2],true));
    return 0;
}
