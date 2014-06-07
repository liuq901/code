#include <cstdio>
typedef long long ll;
int f[1000010];
void init()
{
    const int n=100000000;
    int ans=1;
    f[0]=1;
    for (int i=1;i<=n;i++)
    {
        ans=(ll(i)*ans+1)%10000;
        if (i%100==0)
            f[i/100]=ans;
    }
}
int calc(int n)
{
    int ans=f[n/100];
    for (int i=n/100*100+1;i<=n;i++)
        ans=(ll(i)*ans+1)%10000;
    return(ans);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        static int id=0;
        printf("Case %d: ",++id);
        if (n<7)
            printf("%d\n",calc(n));
        else
            printf("%04d\n",calc(n));
    }
    return(0);
}

