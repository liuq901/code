#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        static int id=0;
        printf("Case %d:\n",++id);
        for (int i=1;i<=10;i++)
        {
            n=n*n%1000000/100;
            printf("%d\n",n);
        }
    }
    return(0);
}

