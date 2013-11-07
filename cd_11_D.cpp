#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[30][30],f[530000][20];
bool flag[30][30];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--,y--;
        a[x][++a[x][0]]=y;
        a[y][++a[y][0]]=x;
        flag[x][y]=flag[y][x]=true;
        f[1<<x|1<<y][max(x,y)]=1;
    }
    ll ans=0;
    for (int i=1;i<1<<n;i++)
    {
        int id;
        for (int j=0;j<n;j++)
            if (i>>j&1)
            {
                id=j;
                break;
            }
        for (int j=0;j<n;j++)
        {
            if (f[i][j]==0)
                continue;
            if (flag[id][j])
                ans+=f[i][j];
            for (int k=1;k<=a[j][0];k++)
            {
                int x=a[j][k];
                if (i>>x&1 || x<id)
                    continue;
                f[i|1<<x][x]+=f[i][j];
            }
        }
    }
    printf("%I64d\n",(ans-m)/2);
    return(0);
}

