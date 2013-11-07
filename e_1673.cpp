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
        printf("Scenario #%d:\n%I64d\n\n",++id,ll(n+m)*(m-n+1)/2);
    }
    return(0);
}

