#include <cstdio>
const int N=1000010;
int a[N],p[N],ans[N];
bool f[N],flag[N];
void init()
{
    int n=1000001,m=0;
    for (int i=1;i<=n;i+=4)
        a[++m]=i;
    for (int i=2;a[i]*a[i]<=n;i++)
    {
        if (f[a[i]])
            continue;
        for (int j=i;a[i]*a[j]<=n;j++)
            f[a[i]*a[j]]=true;
    }
    for (int i=2;i<=m;i++)
        if (!f[a[i]])
            p[++p[0]]=a[i];
    for (int i=1;p[i]*p[i]<=n;i++)
        for (int j=i;p[i]*p[j]<=n;j++)
            flag[p[i]*p[j]]=true;
    for (int i=1;i<=n;i++)
        ans[i]=ans[i-1]+flag[i];
}
int main()
{
    init();
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        printf("%d %d\n",n,ans[n]);
    }
    return(0);
}

