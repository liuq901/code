#include <cstdio>
int a[1010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int k=2;
    for (int i=2;i<n;i++)
        if (a[i-1]+a[i]+a[i+1]>a[k-1]+a[k]+a[k+1])
            k=i;
    printf("%d %d\n",a[k-1]+a[k]+a[k+1],k);
    return(0);
}

