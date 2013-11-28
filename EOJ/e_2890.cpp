#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
pair <int,int> a[60];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].first);
            a[i].second=i;
        }
        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);
        for (int i=1;i<=m;i++)
        {
            int x;
            scanf("%d",&x);
            printf("%d%c",a[x].second,i==m?'\n':' ');
        }
    }
    return(0);
}

