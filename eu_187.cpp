#include <cstdio>
typedef long long ll;
bool f[100000010];
int m,p[100000010];
void init()
{
    for (int i=2;i*i<=100000000;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=100000000;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=100000000;i++)
    {
        if (f[i])
            continue;
        p[++m]=i;
    }
}
int main()
{
    init();
    int ans=0;
    for (int i=1;i<=m;i++)
        for (int j=i;j<=m;j++)
        {
            if (ll(p[i])*p[j]>=100000000)
                break;
            ans++;
        }
    printf("%d\n",ans);
    return(0);
}

