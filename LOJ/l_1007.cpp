#include <cstdio>
typedef unsigned long long ll;
int p[5000010];
bool f[5000010];
ll s[5000010];
void init()
{
    const int n=5000000;
    for (int i=2;i*i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=n;j++)
        {
            f[i*j]=true;
            p[i*j]=i;
        }
    }
    for (int i=2;i<=n;i++)
        if (!f[i])
            p[i]=i;
    for (int i=2;i<=n;i++)
    {
        int x=i;
        for (int j=i;j!=1;)
        {
            x-=x/p[j];
            int x=p[j];
            while (j%x==0)
                j/=x;
        }
        s[i]=s[i-1]+ll(x)*x;
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        static int id=0;
        printf("Case %d: %llu\n",++id,s[y]-s[x-1]);
    }
    return(0);
}

