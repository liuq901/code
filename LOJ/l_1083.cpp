#include <cstdio>
#include <algorithm>
using namespace std;
int Log[30010],f[15][30010];
void init()
{
    Log[1]=0;
    for (int i=2;i<=30000;i++)
    {
        Log[i]=Log[i-1];
        if (i&i-1)
            continue;
        Log[i]++;
    }
}
int calc(int l,int r)
{
    int t=Log[r-l+1];
    return(min(f[t][l],f[t][r-(1<<t)+1]));
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&f[0][i]);
        for (int i=1;i<=Log[n];i++)
            for (int j=1;j<=n;j++)
            {
                if (j+(1<<i)-1>n)
                    break;
                f[i][j]=min(f[i-1][j],f[i-1][j+(1<<i-1)]);
            }
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            int l=1,r=i,L,R;
            while (l<=r)
            {
                int mid=l+r>>1;
                if (calc(mid,i)==f[0][i])
                    L=mid,r=mid-1;
                else
                    l=mid+1;
            }
            l=i,r=n;
            while (l<=r)
            {
                int mid=l+r>>1;
                if (calc(i,mid)==f[0][i])
                    R=mid,l=mid+1;
                else
                    r=mid-1;
            }
            ans=max(ans,f[0][i]*(R-L+1));
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

