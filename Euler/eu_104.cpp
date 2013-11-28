#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
bool check(int x)
{
    bool f[10]={0};
    while (x)
    {
        f[x%10]=true;
        x/=10;
    }
    return(count(f+1,f+10,true)==9);
}
int first(ll x)
{
    while (x>=1e9)
        x/=10;
    return(x);
}
int f[1000000];
ll a[1000000];
int main()
{
    f[1]=f[2]=1;
    a[1]=a[2]=1;
    for (int i=3;;i++)
    {
        f[i]=(f[i-1]+f[i-2])%1000000000;
        a[i]=a[i-1]+a[i-2];
        if (a[i]>=1e18)
        {
            a[i]/=10;
            a[i-1]/=10;
        }
        if (check(f[i]) && check(first(a[i])))
        {
            printf("%d\n",i);
            break;
        }
    }
    return(0);
}

