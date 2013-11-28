#include <cstdio>
int a[10010];
int main()
{
    int m,d1,d2;
    scanf("%d%d%d",&m,&d1,&d2);
    int n=m*d1;
    for (int i=1;i<=d2;i++)
        a[i]=n/d2;
    n%=d2;
    for (int i=1;i<=n;i++)
        a[i]++;
    for (int i=1;i<=d2;i++)
        printf("%d%c",a[i],i==d2?'\n':' ');
    return(0);
}

