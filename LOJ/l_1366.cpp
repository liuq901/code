#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int value[2000010],a[1010][1010];
void init()
{
    memset(value,-1,sizeof(value));
    for (int i=0;i<=1414;i++)
        value[i*i]=i;
    for (int i=0;i<=1000;i++)
        for (int j=0;j<=1000;j++)
            a[i][j]=value[i*i+j*j];
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        ll ans=0;
        for (int i=0;i<=n;i++)
            for (int j=0;j<=m;j++)
            {
                if (a[i][j]<=1 || i+a[i][j]>n || j+a[i][j]>m)
                    continue;
                int now=0;
                for (int k=1;k<a[i][j];k++)
                {
                    int l=max(max(2*k,2*(a[i][j]-k)),i+a[i][j]),r=max(max(2*k,2*(a[i][j]-k)),j+a[i][j]);
                    if (l<=n && r<=m)
                        now+=(n-l+1)*(m-r+1);
                }
                if (i>0 && j>0)
                    now<<=1;
                ans+=now;
            }
        static int id=0;
        printf("Case %d: %lld\n",++id,ans);
    }
    return(0);
}

