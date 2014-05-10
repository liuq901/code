#include <cstdio>
int a[1010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int l=0,r=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            r+=a[i];
        }
        int ans;
        while (l<=r)
        {
            int mid=l+r>>1,sum=0,num=0;
            for (int i=1;i<=n;i++)
                if (sum+a[i]>mid)
                {
                    if (a[i]>mid)
                    {
                        num=m+1;
                        break;
                    }
                    num++;
                    sum=a[i];
                }
                else
                    sum+=a[i];
            num+=sum>0;
            if (num<=m)
                ans=mid,r=mid-1;
            else
                l=mid+1;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

