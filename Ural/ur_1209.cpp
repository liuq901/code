#include <cstdio>
typedef long long ll;
int calc(int n)
{
    ll l=0,r=100000,ans;
    while (l<=r)
    {
        ll mid=l+r>>1,t=mid*(mid+1)>>1;
        if (t<n)
            l=mid+1,ans=mid;
        else
            r=mid-1;
    }
    int p=n-(ans*(ans+1)>>1);
    return(p==1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        printf("%d%c",calc(n),T?' ':'\n');
    }
    return(0);
}

