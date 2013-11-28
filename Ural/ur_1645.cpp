#include <cstdio>
int a[2010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
    {
        int k;
        for (int j=1;j<=n;j++)
            if (a[j]==i)
            {
                k=j;
                break;
            }
        int lower,upper;
        lower=upper=k;
        for (int j=1;j<k;j++)
            if (a[j]<i)
                lower--;
        for (int j=k+1;j<=n;j++)
            if (a[j]>i)
                upper++;
        printf("%d %d\n",lower,upper);
    }
    return(0);
}

