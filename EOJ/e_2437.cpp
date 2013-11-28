#include <cstdio>
#include <vector>
#include <algorithm>
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
vector <int> ans;
int main()
{
    int a,b;
    while (scanf("%d%d",&a,&b)==2)
    {
        if (a>b)
            swap(a,b);
        ans.clear();
        for (int i=a;i>0 && i<=b;i++)
            if (isprime(i))
                ans.push_back(i);
        if (ans.empty())
            printf("no prime number.\n");
        else
            for (int i=0;i<ans.size();i++)
                printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    }
    return(0);
}

