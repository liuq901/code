#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010],b[100010],c[100010],q[100010];
void calc(int a[],int n,int D,int ans[])
{
    int l=1,r=0;
    for (int i=1;i<=n;i++)
    {
        while (l<=r && i-q[l]>=D)
            l++;
        while (l<=r && a[i]>=a[q[r]])
            r--;
        q[++r]=i;
        ans[i]=a[q[l]];
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,D;
        scanf("%d%d",&n,&D);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        calc(a,n,D,b);
        for (int i=1;i<=n;i++)
            a[i]*=-1;
        calc(a,n,D,c);
        int ans=0;
        for (int i=1;i<=n;i++)
            ans=max(ans,b[i]+c[i]);
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

