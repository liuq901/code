#include <cstdio>
int a[260],b[260];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (!n)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for (int i=2;i<=n;i<<=1)
        {
            for (int j=1;j<=i/2;j++)
            {
                b[2*j-1]=(a[j]+a[j+i/2])/2;
                b[2*j]=(a[j]-a[j+i/2])/2;
            }
            for (int j=1;j<=i;j++)
                a[j]=b[j];
        }
        for (int i=1;i<=n;i++)
            printf("%d%c",a[i],i==n?'\n':' ');
    }
    return(0);
}

