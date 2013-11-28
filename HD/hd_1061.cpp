#include <cstdio>
const int mod=10;
int power(int x,int y)
{
    x%=mod;
    int ans=1;
    for (;y;y>>=1)
    {
        if (y&1)
            ans=ans*x%mod;
        x=x*x%mod;
    }
    return(ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",power(n,n));
    }
    return(0);
}

