#include <cstdio>
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        int sum=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            sum+=x;
        }
        int m;
        scanf("%d",&m);
        for (int i=1;i<=m;i++)
            scanf("%*d");
        if (sum==0)
            printf("0.00\n");
        else if (n==m)
            printf("inf\n");
        else
            printf("%.2f\n",double(sum)/(n-m));
    }
    return(0);
}

