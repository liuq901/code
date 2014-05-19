#include <cstdio>
int calc(int n)
{
    int ret=0;
    while (n)
    {
        ret+=n/5;
        n/=5;
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int l=0,r=(1<<30)-1,ans;
        while (l<=r)
        {
            int mid=l+r>>1;
            if (calc(mid)>=n)
                r=mid-1,ans=mid;
            else
                l=mid+1;
        }
        static int id=0;
        printf("Case %d: ",++id);
        if (calc(ans)==n)
            printf("%d\n",ans);
        else
            printf("impossible\n");
    }
    return(0);
}

