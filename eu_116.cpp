#include <cstdio>
#include <cstring>
typedef long long ll;
int n=50;
ll f[60];
ll calc(int x)
{
    memset(f,0,sizeof(f));
    f[0]=1;
    ll ret=0;
    for (int i=x;i<=n;i++)
    {
        for (int j=0;j<=i-x;j++)
            f[i]+=f[j];
        ret+=f[i];
    }
    return(ret);
}
int main()
{
    ll ans=calc(2)+calc(3)+calc(4);
    printf("%lld\n",ans);
    return(0);
}

