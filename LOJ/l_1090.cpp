#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int two[1000010],five[1000010];
void init()
{
    const int n=1000000;
    for (int i=1;i<=n;i++)
    {
        if (i%2==0)
            two[i]=two[i/2]+1;
        if (i%5==0)
            five[i]=five[i/5]+1;
    }
    for (int i=1;i<=n;i++)
    {
        two[i]+=two[i-1];
        five[i]+=five[i-1];
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,r,p,q;
        scanf("%d%d%d%d",&n,&r,&p,&q);
        ll u=two[n],v=five[n];
        u-=two[r]+two[n-r];
        v-=five[r]+five[n-r];
        u+=ll(q)*(two[p]-two[p-1]);
        v+=ll(q)*(five[p]-five[p-1]);
        static int id=0;
        printf("Case %d: %lld\n",++id,min(u,v));
    }
    return(0);
}

