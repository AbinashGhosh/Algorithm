#include <cstdio>
#include <algorithm>
using namespace std;
#define x first
#define y second
typedef pair<int, int> pii;
int d;
pii extEuclid(int a,int b)
{
    if(b==0) {d=a;return pii(1,0);}
    else
    {
        pii d=extEuclid(b,a%b);
        return pii(d.y,d.x-d.y*(a/b));
    }
}
int main()
{
    int a ,b;
    while(scanf("%d%d",&a,&b)==2)
    {
        pii ret= extEuclid(a,b);
        printf("%d %d %d\n",ret.x,ret.y,d);
    }
    return 0;
}


