#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000010];
bool f[1000010];
void init()
{
    for (int i=2;i*i<=1000000;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=1000000;j++)
            f[i*j]=true;
    }
    f[1]=true;
    for (int i=1;i<=1000000;i++)
        a[i]=a[i-1]+1-f[i];
}
int main()
{
    init();
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            int l=max(1,x-y),r=min(1000000,x+y);
            ans+=a[r]-a[l-1]-1;
        }
        printf("%d\n",ans);
    }
    return(0);
}

