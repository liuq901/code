#include <cstdio>
typedef long long ll;
const int mod=1000000007;
int power(int x,int y)
{
    int ret=1;
    for (;y;y>>=1)
    {
        if (y&1)
            ret=ll(ret)*x%mod;
        x=ll(x)*x%mod;
    }
    return(ret);
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    printf("%d\n",power(m,n));
    return(0);
}

