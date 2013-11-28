#include <cstdio>
typedef long long ll;
bool f[1000010];
int a[1000010],p[1000010];
int main()
{
    for (int i=2;i*i<=1000000;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=1000000;j++)
        {
            f[i*j]=true;
            p[i*j]=i;
        }
    }
    a[1]=1;
    for (int i=2;i<=1000000;i++)
    {
        if (!f[i])
        {
            a[i]=i-1;
            continue;    
        }
        int x=i;
        while (x%p[i]==0)
            x/=p[i];
        if (x==1)
            a[i]=i/p[i]*(p[i]-1);
        else
            a[i]=a[x]*a[i/x];
    }
    ll ans=0;
    for (int i=2;i<=1000000;i++)
        ans+=a[i];
    printf("%lld\n",ans);
    return(0);
}

