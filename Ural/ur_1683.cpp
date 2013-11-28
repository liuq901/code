#include <cstdio>
int a[100000];
int main()
{
    int n;
    scanf("%d",&n);
    while (n!=1)
    {
        a[++a[0]]=n/2;
        n=(n+1)/2;
    }
    printf("%d\n",a[0]);
    for (int i=1;i<=a[0];i++)
        printf("%d%c",a[i],i==a[0]?'\n':' ');
    return(0);
}

