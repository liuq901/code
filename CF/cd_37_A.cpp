#include <cstdio>
#include <algorithm>
using namespace std;
int a[1010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int sum=0,ans=0,now=0,p=0;
    for (int i=1;i<=n;i++)
    {
        if (now!=a[i])
        {
            sum++;
            now=a[i];
            p=1;
        }
        else
            p++;
        ans=max(ans,p);
    }
    printf("%d %d\n",ans,sum);
    return(0);
}

