#include <cstdio>
typedef long long ll;
ll calc(int first,int last,int num)
{
    return(ll(first+last)*num/2);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        static int id=0;
        printf("Case %d: ",++id);
        if (m<n || m>k*n)
            printf("0\n");
        else
        {
            int x=(m-n)/(k-1);
            ll ans=calc(k,k*x,x)+calc(x+1-n+m,m-1,n-x-1);
            x=(k*n-m)/(k-1);
            ans-=calc(1,x,x)+calc(k*(x+1)-k*n+m,m-k,n-x-1);
            printf("%lld\n",ans+n-1);
        }
    }
    return(0);
}

