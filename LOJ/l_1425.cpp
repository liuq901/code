#include <cstdio>
int a[100010];
bool check(int k,int n)
{
    for (int i=1;i<=n;i++)
    {
        int delta=a[i]-a[i-1];
        if (delta>k)
            return(false);
        if (delta==k)
            k--;
    }
    return(true);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int l=0,r=1<<30,ans;
        while (l<=r)
        {
            int mid=l+r>>1;
            if (check(mid,n))
                ans=mid,r=mid-1;
            else
                l=mid+1;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

