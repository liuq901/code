#include <cstdio>
#include <algorithm>
using namespace std;
int a[50010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%*d%d",&a[i]);
        sort(a+1,a+n+1);
        int ans=0;
        for (int i=1,j;i<=n;i=j)
        {
            ans++;
            for (j=i;j<=n && a[j]<=a[i]+m;j++);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

