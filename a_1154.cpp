#include <cstdio>
int tot,a[300010],ans[300010];
bool f[300010];
void init()
{
    for (int i=2;i<=300000;i++)
    {
        if (i%7!=1 && i%7!=6 || f[i])
            continue;
        a[++tot]=i;
        for (int j=2*i;j<=300000;j+=i)
            f[j]=true;
    }
}
int main()
{
    init();
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==1)
            break;
        int m=0;
        for (int i=1;i<=tot;i++)
        {
            if (a[i]>n)
                break;
            if (n%a[i]==0)
                ans[++m]=a[i];
        }
        printf("%d:",n);
        for (int i=1;i<=m;i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return(0);
}

