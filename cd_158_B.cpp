#include <cstdio>
#include <algorithm>
using namespace std;
int a[10];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a[x]++;
    }
    int ans=a[4]+a[3];
    a[1]=max(0,a[1]-a[3]);
    ans+=a[2]/2;
    a[2]%=2;
    if (a[2]==1)
    {
        ans++;
        a[1]=max(0,a[1]-2);
    }
    ans+=a[1]/4+(a[1]%4!=0);
    printf("%d\n",ans);
    return(0);
}

