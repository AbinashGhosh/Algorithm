//Abinash Ghosh
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

string text;               // given text;
int freq[130];             // frequency of character

struct node{               // a node have a data(d), left child(l),right child(r),and frequency
    char d;
    int n,l,r,f;
    node(){}
    node(char ch,int nn,int a,int b,int c){
        d=ch,n=nn,l=a,r=b,f=c;
    }
    bool operator<(const node &p)const{
        return f>p.f;
    }
}tree[10000];
string code[130];
void print(node root,string c)
{
    if(root.l!=-1)print(tree[root.l],c+'0');
    if(root.r!=-1)print(tree[root.r],c+'1');
    if(root.l==-1&&root.r==-1)
        code[root.d]=c;
}
int main()
{
    READ("haffman.in");
    //WRITE("out.out");
    char s[1000];
    while(gets(s))
    {
        if(text!="")text+="\n";
        text+=s;
    }
    FOR(i,0,(int)text.size()-1)
        freq[text[i]]++;
    int last=0;
    priority_queue<node>Q;
    FOR(i,0,128)
        if(freq[i]>0)
        {
            node temp(i,last,-1,-1,freq[i]);
            tree[last++]=temp;
            Q.push(temp);
        }
    while(Q.size()>1)
    {
        node left=Q.top();Q.pop();
        node right=Q.top();Q.pop();
        node newnode('$',last,left.n,right.n,left.f+right.f);
        tree[last++]=newnode;
        Q.push(newnode);
    }
    print(Q.top(),"");
    char show;
    FOR(i,0,128)
        if(freq[i]>0){
            show=(char)i;
            pr3(show,"= ",code[i]);
        }
    return 0;
}

