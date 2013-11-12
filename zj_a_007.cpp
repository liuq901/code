#include <cstdio>
int m,p[50000];
bool f[50000];
void init()
{
    int n=46340;
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
}
bool prime(int x)
{
    for (int i=1;i<=m;i++)
    {
        if (p[i]*p[i]>x)
            break;
        if (x%p[i]==0)
            return(false);
    }
    return(true);
}
int main()
{
    init();
    int n;
    while (scanf("%d",&n)==1)
        printf("%s\n",prime(n)?"Ù|”µ":"·ÇÙ|”µ");
    return(0);
}

