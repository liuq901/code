#include <cstdio>
bool f[10010];
int a[10010],ans[10010];
void init()
{
    for (int i=2;i*i<=10000;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=10000;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=10000;i++)
        if (!f[i])
            a[++a[0]]=i;
    for (int i=1;i<=a[0];i++)
        for (int j=i+1;j<=a[0];j++)
            if (a[i]+a[j]<=10000)
                ans[a[i]+a[j]]++;
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
        printf("%d\n",ans[n]);
    }
    return(0);
}

