#include <cstdio>
#include <cstring>
int b[20],a[210][3];
double f[32770][20];
bool ok[32770][20];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=z,a[i+m][2]=b[y],b[y]=i+m;
        }
        memset(f,0,sizeof(f));
        memset(ok,0,sizeof(ok));
        for (int i=0;i<n;i++)
            ok[(1<<n)-1^1<<i][i]=true;
        for (int i=(1<<n)-1;i>=0;i--)
            for (int j=0;j<n;j++)
            {
                int cnt=0;
                for (int k=b[j];k;k=a[k][2])
                {
                    int x=a[k][0];
                    cnt+=!(i>>x&1) && ok[i|1<<j][x];
                }
                if (cnt==0)
                    continue;
                for (int k=b[j];k;k=a[k][2])
                {
                    int x=a[k][0];
                    if (i>>x&1 || !ok[i|1<<j][x])
                        continue;
                    f[i][j]+=f[i|1<<j][x]+a[k][1];
                }
                f[i][j]=(f[i][j]+5)/cnt;
                ok[i][j]=true;
            }
        static int id=0;
        printf("Case %d: %.10f\n",++id,f[0][0]);
    }
    return(0);
}

