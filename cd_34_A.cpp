#include <cstdio>
#include <cstdlib>
int a[110];
int main()
{
    int mi=1<<30,x0,n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    a[0]=a[n];
    for (int i=1;i<=n;i++)
    {
        int p=abs(a[i]-a[i-1]);
        if (p<mi)
            mi=p,x0=i;
    }
    printf("%d %d\n",x0==1?n:x0-1,x0);
    return(0);
}

