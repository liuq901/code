#include <cstdio>
typedef long long ll;
const ll inf=1000000000000000000LL;
ll f[100];
bool a[110];
int main()
{
    f[1]=1;
    f[2]=2;
    int n;
    for (int i=3;;i++)
    {
        f[i]=f[i-2]+f[i-1];
        if (f[i]>=inf)
        {
            n=i;
            break;
        }
    }
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll m;
        scanf("%I64d",&m);
        for (int i=n;i;i--)
        {
            a[i]=m>=f[i];
            if (a[i])
                m-=f[i];
        }
        ll x,y,z;
        x=1,y=z=0;
        for (int i=1;i<=n;i++)
        {
            if (!a[i])
                continue;
            ll t=x+y;
            y=x*(i-z-1>>1)+y*(i-z>>1);
            x=t,z=i;
        }
        printf("%I64d\n",x+y);
    }
    return(0);
}

