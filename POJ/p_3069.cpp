#include <cstdio>
#include <algorithm>
using namespace std;
int a[1010];
int main()
{
    while (1)
    {
        int r,n;
        scanf("%d%d",&r,&n);
        if (r==-1 && n==-1)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int ans=0;
        for (int i=1;i<=n;)
        {
            int j=i;
            while (j<=n && a[j]-a[i]<=r)
                j++;
            ans++;
            int pos=a[j-1];
            while (j<=n && a[j]-pos<=r)
                j++;
            i=j;
        }
        printf("%d\n",ans);
    }
    return(0);
}

