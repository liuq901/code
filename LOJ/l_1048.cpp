#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1010],s[1010];
int calc(int n,int mid)
{
    int pre=0,cnt=1;
    for (int i=1;i<=n;i++)
        if (s[i]-s[pre]>mid)
        {
            cnt++;
            pre=i-1;
        }
    return(cnt);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        n++,m++;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&a[i]);
            s[i]=s[i-1]+a[i];
        }
        int l=*max_element(a+1,a+n+1),r=s[n],ans;
        while (l<=r)
        {
            int mid=l+r>>1;
            if (calc(n,mid)<=m)
                ans=mid,r=mid-1;
            else
                l=mid+1;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
        int pre=0;
        for (int i=1;i<=n;i++)
            if (s[i]-s[pre]>ans || n-i+2==m)
            {
                printf("%d\n",s[i-1]-s[pre]);
                pre=i-1;
                m--;
            }
        printf("%d\n",s[n]-s[pre]);
    }
    return(0);
}

