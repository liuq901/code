#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
pair <int,int> a[1000010];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].second);
            a[i].first=0;
            for (int j=0;j<4;j++)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                a[i].first+=x*60+y;
            }
        }
        sort(a+1,a+n+1);
        printf("%d\n%d\n%d\n",a[1].second,a[2].second,a[n-1].second);
    }
    return(0);
}

