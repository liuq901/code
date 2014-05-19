#include <cstdio>
int calc(int n)
{
    return(n/3*2+(n%3==2));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        static int id=0;
        printf("Case %d: %d\n",++id,calc(r)-calc(l-1));
    }
    return(0);
}

