#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
const int inf=1<<30;
pair <int,int> a[300010];
int ans[100010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            a[i]=make_pair(l,-1);
            a[i+n]=make_pair(r,inf);
        }
        for (int i=1;i<=m;i++)
        {
            int x;
            scanf("%d",&x);
            a[i+2*n]=make_pair(x,i);
        }
        sort(a+1,a+2*n+m+1);
        int now=0;
        for (int i=1;i<=2*n+m;i++)
            if (a[i].second==-1)
                now++;
            else if (a[i].second==inf)
                now--;
            else
                ans[a[i].second]=now;
        static int id=0;
        printf("Case #%d:\n",++id);
        for (int i=1;i<=m;i++)
            printf("%d\n",ans[i]);
    }
    return(0);
}

