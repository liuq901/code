#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
pair <int,int> a[50010],b[50010];
int solve(pair <int,int> a[],int n)
{
    sort(a+1,a+n+1);
    int tot=0;
    for (int i=1;i<=n;i++)
        tot+=a[i].second;
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        sum+=a[i].second;
        if (2*sum>=tot)
            return(a[i].first);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%*d%*d%d",&n);
        for (int i=1;i<=n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i]=make_pair(x,z);
            b[i]=make_pair(y,z);
        }
        static int id=0;
        printf("Case %d: %d %d\n",++id,solve(a,n),solve(b,n));
    }
    return(0);
}

