#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
pair <int,int> a[110];
int main()
{
    while (1)
    {
        int m;
        scanf("%d",&m);
        if (m==0)
            break;
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d%d",&a[i].first,&a[i].second);
        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            int now=min(m,a[i].second);
            ans+=a[i].first*now;
            m-=now;
        }
        printf("%d\n",ans);
    }
    return(0);
}

