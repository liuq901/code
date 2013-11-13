#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b,ll &x,ll &y)
{
    if (b==0)
    {
        x=1;
        y=0;
        return(a);
    }
    ll ret=gcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-a/b*y;
    return(ret);
}
int main()
{
    int a,n;
    while (scanf("%d%d",&a,&n)==2)
    {
        if (n==1)
        {
            printf("%s\n",a==1?"1":"No Inverse");
            continue;
        }
        ll x,y;
        if (gcd(a,n,x,y)!=1)
            printf("No Inverse\n");
        else
            printf("%d\n",(x%n+n)%n);
    }
    return(0);
}

