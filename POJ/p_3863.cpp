#include <cstdio>
#include <algorithm>
using namespace std;
int calc(int n,int u,int d)
{
    int ans=(n*d+1)/(u+d);
    if ((n*d+1)%(u+d)!=0)
        ans++;
    return(u*ans-d*(n-ans));
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int ans=2147483647;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        ans=min(ans,calc(n,x,y));
    }
    printf("%d\n",ans);
    return(0);
}

