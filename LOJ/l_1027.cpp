#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int sum=0,cnt=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            cnt+=x<0;
            sum+=abs(x);
        }
        static int id=0;
        printf("Case %d: ",++id);
        if (cnt==n)
            printf("inf\n");
        else
        {
            int p=__gcd(n-cnt,sum);
            printf("%d/%d\n",sum/p,(n-cnt)/p);
        }
    }
    return(0);
}

