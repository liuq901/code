#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
inline bool cmp(const pair <int,int> &a,const pair <int,int> &b)
{
    return(a.first<b.first || a.first==b.first && a.second>b.second);
}
pair <int,int> a[20010];
int f[20010];
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
        sort(a+1,a+n+1,cmp);
        int best=0;
        f[0]=1<<30;
        for (int i=1;i<=n;i++)
        {
            int l=0,r=best,ans=-1,x=a[i].second;
            while (l<=r)
            {
                int mid=l+r>>1;
                if (f[mid]>=x)
                    l=mid+1,ans=mid;
                else
                    r=mid-1;
            }
            if (ans==best)
                f[++best]=x;
            else
                f[ans+1]=max(f[ans+1],x);
        }
        printf("%d\n",best);
    }
    return(0);
}

