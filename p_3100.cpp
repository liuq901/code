#include <cstdio>
#include <cstdlib>
typedef long long ll;
bool check(int a,int n,int b)
{
    ll ret=1;
    for (int i=1;i<=n;i++)
    {
        ret*=a;
        if (ret>b)
            return(false);
    }
    return(true);
}
int power(int a,int n)
{
    int ret=1;
    for (int i=1;i<=n;i++)
        ret*=a;
    return(ret);
}
int main()
{
    while (1)
    {
        int b,n;
        scanf("%d%d",&b,&n);
        if (b==0 && n==0)
            break;
        int l=1,r=1000000,ans;
        while (l<=r)
        {
            int mid=l+r>>1;
            if (check(mid,n,b))
                ans=mid,l=mid+1;
            else
                r=mid-1;
        }
        if (abs(power(ans,n)-b)<=abs(power(ans+1,n)-b))
            printf("%d\n",ans);
        else
            printf("%d\n",ans+1);
    }
    return(0);
}

