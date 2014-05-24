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
        printf("Case %d: %s\n",++id,__builtin_parity(n)?"odd":"even");
    }
    return(0);
}

