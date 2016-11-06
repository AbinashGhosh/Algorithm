#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
using  namespace  std;

#define PI acos(-1.0)
#define MAX 10000007
#define MOD 10000007
#define EPS 1e-9

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define Sort(x) sort(x.begin(),x.end())
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define pr(x) cout<<x<<"\n"
#define pr2(x,y) cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n";
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

typedef  long long ll;
typedef  pair <int, int> pii;
typedef  pair <double , double> pdd;
typedef  pair <ll , ll > pll;
typedef  vector <int> vi;
typedef  vector <pii> vpii;
typedef  vector <ll > vl;

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1, 0, 1};
//int dy[]={0,1,1, 1, 0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1, 1, 2};
//int dy[]={1,2, 2, 1,-1,-2,-2,-1};//Knight Direction


class Matrix
{
public:
    int row,col;
    ll value[5][5];
    void clear()
    {
        mem(value,0);
        row=0;
        col=0;
    }

    void identify(int x)
    {
        clear();
        row=x;
        col=x;
        FOR(i,0,row-1)
            value[i][i]=1;
    }
    Matrix operator * (Matrix b)
    {
        Matrix c;
        c.clear();
        c.row=row;
        c.col=b.row;

        FOR(i,0,row-1)
            FOR(j,0,b.col-1)
                FOR(k,0,col-1)
                {
                    c.value[i][j]+=value[i][k]*b.value[k][j];
                    c.value[i][j]%=MOD;
                }
        return c;
    }

    Matrix operator ^ (ll p)
    {
        Matrix res,x;
        res.identify(row);
        x=*(this);
        while(p)
        {
            if(p&1)res =res*x;
            x=x*x;
            p=p>>1;
        }
        return res;
    }
};
Matrix a,b;
void setMvalue(Matrix &x)
{
    scanf("%d%d",&x.row,&x.col);
    FOR(i,0,x.row-1)
       FOR(j,0,x.col-1)
           scanf("%d",&x.value[i][j]);
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    Matrix x,y;
    setMvalue(a);
    setMvalue(b);
    y=b^(10000000000-2);

    x=y*a;
    printf("  %lld\n",x.value[0][0]);
    return 0;
}
/*
2 1
1
1
2 2
1 1
1 0
*/
