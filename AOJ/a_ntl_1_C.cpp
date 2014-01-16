#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n,ans;
    scanf("%d%d",&n,&ans);
    for (int i=2;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        ans=ans/__gcd(ans,x)*x;
    }
    printf("%d\n",ans);
    return(0);
}

