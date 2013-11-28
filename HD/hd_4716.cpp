#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        n/=10;
        static int id=0;
        printf("Case #%d:\n",++id);
        printf("*------------*\n");
        for (int i=1;i<=10-n;i++)
            printf("|............|\n");
        for (int i=1;i<=n;i++)
            printf("|------------|\n");
        printf("*------------*\n");
    }
    return(0);
}

