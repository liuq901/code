#include <cstdio>
int a[100010];
int main()
{
    int n,m;
    scanf("%d%d",&m,&n);
    for (int i=1;i<=n;i++)
    {
        a[i]=m/n+m%n;
        m-=a[i];
    }
    for (int i=1;i<=n;i++)
        printf("%d%c",a[i],i==n?'\n':' ');
    printf("%d\n",m);
    return(0);
}

