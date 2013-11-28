#include <cstdio>
typedef long long ll;
ll divider(int n)
{
    ll sum=0;
    for (int i=1;i*i<=n;i++)
        if (n%i==0)
        {
            if (i!=n)
                sum+=i;
            if (n/i!=n && n/i!=i)
                sum+=n/i;
        }
    return(sum);
}
int main()
{
    int L,R,ans;
    double mi=1e20;
    scanf("%d%d",&L,&R);
    if (L==1)
        printf("1\n");
    else
    {
        for (int i=R;i>=L;i--)
        {
            ll p=divider(i);
            if (p==1)
            {
                ans=i;
                break;
            }
            if (double(p)/i<mi)
            {
                mi=double(p)/i;
                ans=i;
            }
        }
        printf("%d\n",ans);
    }
    return(0);
}

