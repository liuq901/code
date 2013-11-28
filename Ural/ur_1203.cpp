#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
pair <int,int> a[100010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&a[i].second,&a[i].first);
    sort(a+1,a+n+1);
    int ans=0,last=-1;
    for (int i=1;i<=n;i++)
        if (a[i].second>last)
        {
            ans++;
            last=a[i].first;
        }
    printf("%d\n",ans);
    return(0);
}

