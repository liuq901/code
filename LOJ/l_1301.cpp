#include <cstdio>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
pair <int,int> a[50010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d%d",&a[i].first,&a[i].second);
        sort(a+1,a+n+1);
        priority_queue <int> Q;
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            if (!Q.empty() && -Q.top()<a[i].first)
                Q.pop();
            Q.push(-a[i].second);
            ans=max(ans,int(Q.size()));
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

