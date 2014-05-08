#include <cstdio>
#include <cstdlib>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        static int id=0;
        printf("Case %d: %d\n",++id,(a+abs(a-b))*4+19);
    }
    return(0);
}

