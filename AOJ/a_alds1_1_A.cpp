#include <cstdio>
int a[110];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
    {
        int k=i;
        for (int j=1;j<i;j++)
            if (a[j]>a[i])
            {
                k=j;
                break;
            }
        int t=a[i];
        for (int j=i;j>k;j--)
            a[j]=a[j-1];
        a[k]=t;
        for (int j=1;j<=n;j++)
            printf("%d%c",a[j],j==n?'\n':' ');
    }
    return(0);
}

