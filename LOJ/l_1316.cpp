#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int s[20],b[510],d[20][510],a[10010][3],f[32770][20];
bool in[510];
void spfa(int id)
{
    queue <int> Q;
    Q.push(s[id]);
    memset(d[id],-1,sizeof(d[id]));
    d[id][s[id]]=0;
    in[s[id]]=true;
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        in[x]=false;
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (d[id][y]==-1 || d[id][x]+a[i][1]<d[id][y])
            {
                d[id][y]=d[id][x]+a[i][1];
                if (!in[y])
                {
                    in[y]=true;
                    Q.push(y);
                }
            }
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,K;
        scanf("%d%d%d",&n,&m,&K);
        for (int i=1;i<=K;i++)
        {
            scanf("%d",&s[i]);
            s[i]++;
        }
        s[0]=1;
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            x++,y++;
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
        }
        for (int i=0;i<=K;i++)
            spfa(i);
        static int id=0;
        printf("Case %d: ",++id);
        if (d[0][n]==-1)
            printf("Impossible\n");
        else
        {
            memset(f,-1,sizeof(f));
            f[0][0]=0;
            int cnt=0,ans=d[0][n];
            for (int i=0;i<1<<K;i++)
                for (int j=0;j<=K;j++)
                {
                    if (f[i][j]==-1)
                        continue;
                    int now=__builtin_popcount(i);
                    if (d[j][n]!=-1 && (now>cnt || now==cnt && f[i][j]+d[j][n]<ans))
                        cnt=now,ans=f[i][j]+d[j][n];
                    for (int k=1;k<=K;k++)
                    {
                        if (i>>k-1&1 || d[j][s[k]]==-1)
                            continue;
                        int &tmp=f[i|1<<k-1][k];
                        if (tmp==-1 || f[i][j]+d[j][s[k]]<tmp)
                            tmp=f[i][j]+d[j][s[k]];
                    }
                }
            printf("%d %d\n",cnt,ans);
        }
    }
    return(0);
}

