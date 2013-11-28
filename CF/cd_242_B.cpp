#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010],b[100010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&a[i],&b[i]);
    int x=*min_element(a+1,a+n+1);
    int y=*max_element(b+1,b+n+1);
    int ans=-1;
    for (int i=1;i<=n;i++)
        if (a[i]==x && b[i]==y)
        {
            ans=i;
            break;
        }
    printf("%d\n",ans);
    return(0);
}

