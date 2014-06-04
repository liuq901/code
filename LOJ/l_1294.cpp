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
        static int id=0;
        printf("Case %d: %lld\n",++id,ll(m)*n/2);
    }
    return(0);
}

