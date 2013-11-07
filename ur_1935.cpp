#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n,m=0,ans=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        ans+=x;
        m=max(m,x);
    }
    printf("%d\n",ans+m);
    return(0);
}

