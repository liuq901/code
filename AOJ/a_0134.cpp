#include <cstdio>
typedef long long ll;
int main()
{
    int n;
    scanf("%d",&n);
    ll sum=0;
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        sum+=x;
    }
    printf("%lld\n",sum/n);
    return(0);
}

