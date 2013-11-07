#include <cstdio>
int a[110];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a[x]=i;
    }
    for (int i=1;i<=n;i++)
        printf("%d%c",a[i],i==n?'\n':' ');
    return(0);
}

