#include <cstdio>
#include <cstring>
typedef long long ll;
const int mod=1000000007;
int b[1010],cnt[1010],a[1010][2],c[1010][1010];
bool flag[1010];
void init()
{
    const int n=1000;
    for (int i=0;i<=n;i++)
    {
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
}
int calc(int x)
{
    int ret=1;
    cnt[x]=0;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0],tmp=calc(y);
        cnt[x]+=cnt[y];
        ret=ll(ret)*tmp%mod*c[cnt[x]][cnt[y]]%mod;
    }
    cnt[x]++;
    return(ret);
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
        memset(b,0,sizeof(b));
        memset(flag,0,sizeof(flag));
        for (int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            flag[y]=true;
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
        }
        for (int i=1;i<=n;i++)
            if (!flag[i])
            {
                static int id=0;
                printf("Case %d: %d\n",++id,calc(i));
                break;
            }
    }
    return(0);
}

