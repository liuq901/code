#include <cstdio>
int a[30];
int main()
{
    int n;
    scanf("%d%d%d",&a[0],&a[1],&n);
    for (int i=2;i<=n;i++)
        a[i]=a[i-1]+a[i-2];
    printf("%d\n",a[n]);
    return(0);
}

