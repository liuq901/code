#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,Q;
        scanf("%d%d",&n,&Q);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            l=lower_bound(a+1,a+n+1,l)-a;
            r=upper_bound(a+1,a+n+1,r)-a-1;
            printf("%d\n",r-l+1);
        }
    }
    return(0);
}

