#include <cstdio>
#include <algorithm>
#define div __div__
using namespace std;
typedef long long ll;
int div[1000010],sum[1000010];
void init()
{
    const int n=1000000;
    for (int i=2;i<=n;i++)
        if (!div[i])
        {
            div[i]=i;
            if (i>n/i)
                continue;
            for (int j=i*i;j<=n;j+=i)
                if (!div[j])
                    div[j]=i;
        }
    for (int i=1;i<=n;i++)
    {
        int cnt=0,last=0;
        for (int j=i;j>1;last=div[j],j/=div[j])
        {
            if (div[j]==last)
            {
                sum[i]=0;
                goto Break;
            }
            cnt^=1;
        }
        if (cnt)
            sum[i]=-1;
        else
            sum[i]=1;
Break:
        sum[i]+=sum[i-1];
    }
}
ll calc(int a,int b)
{
    ll ans=0;
    for (int i=1,j,p,q;i<=a;i=j+1)
    {
        p=a/i;
        q=b/i;
        j=b/q;
        if (a<p*j)
            j=a/p;
        ans+=ll(sum[j]-sum[i-1])*p*q;
    }
    return(ans);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n>m)
            swap(n,m);
        static int id=0;
        printf("Case %d: %lld\n",++id,n==0?m==0?0:1:calc(n,m)+2);
    }
    return(0);
}

