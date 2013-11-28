#include <cstdio>
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        printf("%lld\n",ll(n)*m-1);
    }
    return(0);
}

