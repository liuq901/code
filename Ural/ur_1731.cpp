#include <cstdio>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        printf("%d%c",i,i==n?'\n':' ');
    for (int i=1;i<=m;i++)
        printf("%d%c",i*10000,i==m?'\n':' ');
    return(0);
}

