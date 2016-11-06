/**************************************************
    _|||||_     -||||||||_    -|||    |||-   _|
   _||    ||_    |||    ||     |||    |||   |||
   |||    |||    |||    ||     |||    |||   |||
   |||    |||    |||___||-     |||____|||   |||
   ||||||||||    |||---||_     |||----|||   |||
   |||    |||    |||    ||     |||    |||   |||
   |||    |||    |||    ||     |||    |||   |||
  _|||    |||_  _||||||||-    _|||    |||_  |-
***************************************************/
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iomanip>
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
#include <ctime>
#include <cassert>
#include <limits>
using  namespace  std;

#define PI acos(-1.0)
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define Sort(x) sort(x.begin(),x.end())
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORR(i, b, e) for(int i = b; i >= e; i--)
#define FORI(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define pr(x) cout<<x<<"\n"
#define pr2(x,y) cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n";
#define ppr(a) cout<<a.x<<" "<<a.y<<"\n"
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

typedef  long long ll;
typedef  pair <int, int> pii;
typedef  pair <double , double> pdd;
typedef  pair <ll , ll > pll;
typedef  vector <int> vi;
typedef  vector <pii> vpii;
typedef  vector <ll > vl;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};
//int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

#define MAX 100007
#define EPS 1e-9

#define MOD 1000000007

/// Matrix Expo (nth fibonacci number )
/*
    | Fn   |  = | 1  1 |^(n-1)   | F1 |
    | Fn-1 |    | 1  0 |       * | F0 |
*/
struct matrix
{
    ll v[5][5];
    int row, col; // number of row and column
    matrix (){};
    matrix (int r, int c) : row (r), col (c) {
    memset(v, 0, sizeof v);
  }
};
// multiplies two matrices and returns the result
matrix multiply(matrix a, matrix b)
{
    matrix r(a.row,b.col);
    FOR(i,0,r.row-1){
        FOR(j,0,r.col-1)
            FOR(k,0,a.col-1)
            r.v[i][j] =(r.v[i][j]+a.v[i][k] * b.v[k][j])%MOD;
    }
    return r;
}
///x^p Complexity : d^3 log p
matrix power(matrix x, ll p)
{
    matrix res(x.row,x.col);
    FOR(i,0,res.row-1)res.v[i][i]=1;
    while(p){
        if(p&1)res =multiply(res,x);
        x=multiply(x,x);
        p=p>>1;
    }
    return res;
}
void solve() {
  int a, b, n, m;
  scanf("%d%d%d",&a,&b,&n);
  matrix base(2, 2);
  matrix ans(2, 2);
  base.v[0][0] = base.v[0][1] = base.v[1][0] = 1;
  base.v[1][1] = 0;
  ans=power(base, n - 1);
  printf("%d\n", ((ans.v[0][0] * b) % MOD + (ans.v[0][1] * a) % MOD) % MOD);
}
int main() {

  int tc;
  scanf("%d",&tc);
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
}
