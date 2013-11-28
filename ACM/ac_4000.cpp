#include <cstdio>
int a[510];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        if (n&1)
        {
            int sum=0;
            for (int i=1;i<=n;i++)
                for (int j=i+1;j<=n;j++)
                    sum+=a[i]>a[j];
            printf("%s\n",sum&1?"impossible":"possible");
        }
        else
            printf("possible\n");
    }
    return(0);
}

