#include <cstdio>
int a[10010];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        a[x]++;
    }
    for (int i=1;i<=n;i++)
        printf("%.2f%%\n",a[i]*100.0/m);
    return(0);
}

