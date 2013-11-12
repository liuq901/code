#include <cstdio>
typedef long long ll;
ll f[30010],g[30010];
void init()
{
    f[1]=g[1]=1;
    for (int i=2;i<=30000;i++)
    {
        f[i]=i+f[i-1];
        g[i]=f[i]+g[i-1];
    }
}
int main()
{
    init();
    int n;
    while (scanf("%d",&n)==1)
        printf("%lld %lld\n",f[n],g[n]);
    return(0);
}

