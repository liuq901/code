#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=100010;
bool small[N];
int tot,to[N],big[N],d[N],b[N],color[N],a[2*N][3];
ll ans[2][2],num[N][2],v[1010][1010];
void init(int n)
{
    for (int i=1;i<=tot;i++)
        for (int j=1;j<=tot;j++)
            v[i][j]=0;
    for (int i=1;i<=n;i++)
    {
        if (small[i])
            continue;
        for (int j=b[i];j;j=a[j][2])
        {
            int x=a[j][0];
            if (small[x])
                continue;
            v[to[i]][to[x]]+=a[j][1];
        }
    }
    ans[0][0]=ans[0][1]=ans[1][1]=0;
    for (int i=1;i<=n;i++)
        for (int j=b[i];j;j=a[j][2])
        {
            int x=a[j][0];
            ans[min(color[i],color[x])][max(color[i],color[x])]+=a[j][1];
        }
    for (int i=1;i<=tot;i++)
    {
        int x=big[i];
        num[x][0]=num[x][1]=0;
        for (int j=b[x];j;j=a[j][2])
        {
            int y=a[j][0];
            num[x][color[y]]+=a[j][1];
        }
    }
    ans[0][0]/=2;
    ans[0][1]/=2;
    ans[1][1]/=2;
}
void change(int x)
{
    if (small[x])
    {
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            ans[min(color[x],color[y])][max(color[x],color[y])]-=a[i][1];
            if (!small[y])
                num[y][color[x]]-=a[i][1];
        }
        color[x]^=1;
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            ans[min(color[x],color[y])][max(color[x],color[y])]+=a[i][1];
            if (!small[y])
                num[y][color[x]]+=a[i][1];
        }
    }
    else
    {
        ans[0][color[x]]-=num[x][0];
        ans[color[x]][1]-=num[x][1];
        for (int i=1;i<=tot;i++)
            num[big[i]][color[x]]-=v[to[x]][i];
        color[x]^=1;
        ans[0][color[x]]+=num[x][0];
        ans[color[x]][1]+=num[x][1];
        for (int i=1;i<=tot;i++)
            num[big[i]][color[x]]+=v[to[x]][i];
    }
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=1;i<=n;i++)
        {
            b[i]=d[i]=0;
            scanf("%d",&color[i]);
        }
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=z,a[i+m][2]=b[y],b[y]=i+m;
            d[x]++,d[y]++;
        }
        tot=0;
        for (int i=1;i<=n;i++)
        {
            small[i]=true;
            if (d[i]*d[i]>=m)
            {
                big[++tot]=i;
                to[i]=tot;
                small[i]=false;
            }
        }
        init(n);
        int Q;
        scanf("%d",&Q);
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            char op[10];
            scanf("%s",op);
            if (op[0]=='C')
            {
                int x;
                scanf("%d",&x);
                change(x);
            }
            else
            {
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%I64d\n",ans[min(x,y)][max(x,y)]);
            }
        }
    }
    return(0);
}

