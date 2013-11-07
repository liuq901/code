#include <cstdio>
#include <cstring>
typedef long long ll;
ll a[110];
int main()
{
    int D,n;
    scanf("%d%d",&D,&n);
    int p=1;
    for (int i=1;i<=D;i++)
        p*=10;
    for (int i=1;i<=n;i++)
    {
        double x;
        scanf("%lf",&x);
        a[i]=ll(x*p+0.5)*10;
    }
    p*=10;
    for (int i=1;;i++)
    {
        bool flag=true;
        for (int j=1;j<=n;j++)
        {
            ll x=(a[j]+5)*i,y=(a[j]-5)*i;
            if ((x-1)/p*p<y)
            {
                flag=false;
                break;
            }
        }
        if (flag)
        {
            printf("%d\n",i);
            break;
        }
    }
    return(0);
}

