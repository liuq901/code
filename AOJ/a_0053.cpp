#include <cstdio>
int m,p[1000010],s[1000010];
bool f[1000010];
void init()
{
    int n=1000000;
    for (int i=2;i*i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=n;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=n;i++)
        if (!f[i])
            p[++m]=i;
    for (int i=1;i<=m;i++)
        s[i]=s[i-1]+p[i];
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
        printf("%d\n",s[n]);
    }
    return(0);
}

