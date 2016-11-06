#include<cstdio>
#include<cstring>
void rabin_karp(char s[],char t[])
{
    int slen=strlen(s);
    int tlen=strlen(t);
    long long p = 999983;      // prime number
    long long M = 1000000009;  // prime number
    long long hs=0ll,pw[tlen],h[tlen];
    if(slen>tlen)return;
    // Power of P
    pw[0]=1;
    for(int i=1;i<tlen;i++)pw[i]=(pw[i-1]*p)%M;

    //find hash of s
    for(int i=0;i<slen;i++)hs=(hs+((s[i]-'a'+1)*pw[i]))%M;

    //find hashs of t
    for(int i=0;i<tlen;i++){
        h[i]=((t[i]-'a'+1)*pw[i])%M;
        if(i)h[i]=(h[i]+h[i-1])%M;
    }

    // Compare the hash
    for(int i=0;i+slen-1<tlen;i++){
        long long curh=h[i+slen-1];
        if(i)curh=(curh-h[i-1]+M)%M;
        if(curh==((hs*pw[i])%M))
            printf("%d ",i);
    }
}
int main()
{
    char s[10007],t[10007];
    scanf("%s %s",s,t);
    rabin_karp(s,t);
    return 0;
}
