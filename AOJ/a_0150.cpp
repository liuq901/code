#include <cstdio>
bool f[10010];
int ans[10010];
void init()
{
    for (int i=2;i*i<=10000;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=10000;j++)
            f[i*j]=true;
    }
    for (int i=5;i<=10000;i++)
        ans[i]=!f[i-2] && !f[i]?i:ans[i-1];
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
        printf("%d %d\n",ans[n]-2,ans[n]);
    }
    return(0);
}

