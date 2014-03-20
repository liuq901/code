#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int n,K;
    scanf("%d%d",&n,&K);
    ll a=0,b=0;
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a+=max(0,x-K);
        b+=max(0,K-x);
    }
    printf("%I64d %I64d\n",a,b);
    return(0);
}

