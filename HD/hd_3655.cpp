#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int inf,b[3010],d[4][3010],q[3010],a[400010][3];
bool in[3010],ans[3010],vis[40][3010];
void spfa(int S)
{
    memset(d[S],63,sizeof(d[S]));
    inf=d[S][0];
    int l=0,r=1;
    q[1]=S;
    d[S][S]=0;
    in[S]=true;
    while (l!=r)
    {
        l=l==3005?1:l+1;
        int x=q[l];
        in[x]=false;
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (d[S][x]+a[i][1]<d[S][y])
            {
                d[S][y]=d[S][x]+a[i][1];
                if (!in[y])
                {
                    in[y]=true;
                    r=r==3005?1:r+1;
                    q[r]=y;
                }
            }
        }
    }
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
    {
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=z,a[i+m][2]=b[y],b[y]=i+m;
        }
        for (int i=1;i<=3;i++)
            spfa(i);
        memset(ans,1,sizeof(ans));
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=3;j++)
                if (d[j][i]==inf)
                {
                    ans[i]=false;
                    break;
                }
            for (int j=b[i];j;j=a[j][2])
            {
                int y=a[j][0];
                for (int p=1;p<=3;p++)
                    for (int q=p+1;q<=3;q++)
                        if (d[p][i]+a[j][1]==d[p][y] && d[q][i]+a[j][1]==d[q][y])
                            ans[y]=false;
            }
        }
        int num=count(ans+1,ans+n+1,true);
        if (num==0)
            printf("impossible\n");
        else
        {
            printf("%d\n",num);
            bool first=true;
            for (int i=1;i<=n;i++)
            {
                if (!ans[i])
                    continue;
                if (!first)
                    printf(" ");
                first=false;
                printf("%d",i);
            }
            printf("\n");
        }
    }
    return(0);
}

