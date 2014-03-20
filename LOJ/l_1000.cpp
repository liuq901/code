#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        static int id=0;
        printf("Case %d: %d\n",++id,a+b);
    }
    return(0);
}

