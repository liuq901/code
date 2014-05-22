#include <cstdio>
typedef unsigned long long ull;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ull n;
        scanf("%llu",&n);
        static int id=0;
        printf("Case %d:",++id);
        for (int i=9;i>=0;i--)
        {
            ull m=n*10-i;
            if (m%9==0)
                printf(" %llu",m/9);
        }
        printf("\n");
    }
    return(0);
}

