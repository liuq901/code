#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
int powmod(int x,int n,int mod)
{
    int res=1,p=x;
    while (n)
    {
        if (n&1)
            res=ll(res)*p%mod;
        p=ll(p)*p%mod;
        n>>=1;
    }
    return(res);
}
int mulmod(int x,int y,int mod)
{
    return(ll(x)*y%mod);
}
bool test(int n,int base)
{
    int n2=n-1,res,s=0;
    while (!(n2&1))
    {
        n2>>=1;
        s++;
    }
    res=powmod(base,n2,n);
    if (res==1 || res==n-1)
        return(true);
    s--;
    while (s>=0)
    {
        res=mulmod(res,res,n);
        if (res==n-1)
            return(true);
        s--;
    }
    return(false);
}
bool isprime(int n)
{
    if (n<2)
        return(false);
    if (n<4)
        return(true);
    if (!test(n,2) || !test(n,3))
        return(false);
    if (n<1373653)
        return(true);
    if (!test(n,5))
        return(false);
    if (n<25326001)
        return(true);
    return(test(n,7));
}
vector <int> c;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a,b,k,s;
        scanf("%d%d%d%d",&a,&b,&k,&s);
        c.clear();
        for (int i=a;i<=b;i++)
            if (isprime(i))
                c.push_back(i);
        int ans=0;
        for (int i=k-1;i<c.size();i++)
            ans+=c[i]-c[i-k+1]==s;
        printf("%d\n",ans);
    }
    return(0);
}

