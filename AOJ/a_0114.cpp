#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int calc(int a,int b)
{
    int cnt=0,now=1;
    while (1)
    {
        now=now*a%b;
        cnt++;
        if (now==1)
            break;
    }
    return(cnt);
}
int main()
{
    while (1)
    {
        int a,b,c,d,e,f;
        scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
        if (a==0 && b==0 && c==0 && d==0 && e==0 && f==0)
            break;
        int x=calc(a,b),y=calc(c,d),z=calc(e,f);
        ll ans=ll(x)*y/__gcd(x,y);
        ans*=z/__gcd(ans,ll(z));
        printf("%lld\n",ans);
    }
    return(0);
}

