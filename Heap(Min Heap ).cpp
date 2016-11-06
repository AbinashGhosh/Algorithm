//Abinash Ghosh(Om)
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
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
using  namespace  std;

#define PI acos(-1.0)
#define MAX 10007
#define EPS 1e-9
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define Sort(x) sort(x.begin(),x.end())
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORR(i, b, e) for(int i = b; i >= e; i--)
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


//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};
//int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

struct heap
{
    int n,arr[MAX+1];
    heap(){ n=0;}
    int size(){ return n;}
    void insert(int k)
    {
        if(n==MAX)return;
        arr[++n]=k;
        int p=n;
        while(p>1){
            int par=p/2;
            if(arr[par]>arr[p]){
                swap(arr[par],arr[p]);
                p=par;
            }
            else break;
        }
    }
    int remove()
    {   //remove minimum element
        if(n==0)return -1;
        int k=arr[1];
        arr[1]=arr[n--];
        int p=1;
        while(2*p<=n){
            int ch=2*p;
            if(ch+1<=n)
                if(arr[ch]>arr[ch+1])ch++;
            if(arr[p]>arr[ch]){
                swap(arr[ch],arr[p]);
                p=ch;
            }
            else break;
        }
        return k;
    }
    void print()
    {   // printing the heap
        printf("Number of elements: %d\n", n);
        for( int i = 1; i <= n; i++ ) printf("%d ", arr[i]);
        printf("\n");
    }
};
int main()
{
    //READ("inA.txt");
    //WRITE("outA.txt");
    heap A; // created a heap
    // testing
    FOR(i,1,10)
    {
        A.insert(rand()%9+1);
        A.print();
    }
    FOR(i,1,10)
    {
        if(A.size()>0)
        printf("Deleting %d\n", A.remove());
        A.print();
    }
    return 0;
}




