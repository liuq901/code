#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010],b[100010],f[100010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,Q;
        scanf("%d%d",&n,&Q);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int m=0;
        b[0]=1<<30;
        for (int i=n;i;i--)
        {
            int l=0,r=m,ans;
            while (l<=r)
            {
                int mid=l+r>>1;
                if (a[i]<b[mid])
                    ans=mid,l=mid+1;
                else
                    r=mid-1;
            }
            f[i]=ans+1;
            if (ans==m)
                b[++m]=a[i];
            else
                b[ans+1]=max(b[ans+1],a[i]);
        }
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            int x;
            scanf("%d",&x);
            int k=-1;
            for (int i=1;i<=n;i++)
                if (f[i]>=x)
                {
                    k=i;
                    break;
                }
            if (k==-1)
                printf("Impossible\n");
            else
            {
                bool first=true;
                int now=-1<<30;
                for (int i=1;i<=n;i++)
                    if (f[i]>=x && a[i]>now)
                    {
                        if (!first)
                            printf(" ");
                        first=false;
                        printf("%d",a[i]);
                        now=a[i];
                        if (--x==0)
                            break;
                    }
                printf("\n");
            }
        }
    }
    return(0);
}

