#include <cstdio>
typedef long long ll;
const int mod=1000000007;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char s[510][20];
int to[510][20],a[7510][50];
int power(int x,int y)
{
    int ret=1;
    for (;y;y>>=1)
    {
        if (y&1)
            ret=ll(ret)*x%mod;
        x=ll(x)*x%mod;
    }
    return(ret);
}
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%s",s[i]+1);
        int N=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (s[i][j]=='.')
                    to[i][j]=++N;
        for (int i=1;i<=N;i++)
            for (int j=0;j<=2*m;j++)
                a[i][j]=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                if (s[i][j]!='.')
                    continue;
                for (int k=0;k<4;k++)
                {
                    int x=i+c[k][0],y=j+c[k][1];
                    if (x>=1 && x<=n && y>=1 && y<=m && s[x][y]=='.')
                    {
                        a[to[i][j]][to[x][y]-to[i][j]+m]=-1;
                        a[to[i][j]][m]++;
                    }
                }
            }
        int ans=1;
        for (int i=1;i<N;i++)
        {
            if (a[i][m]==0)
            {
                ans=0;
                break;
            }
            ans=ll(ans)*a[i][m]%mod;
            int p=power(a[i][m],mod-2);
            for (int j=m+1;j<=2*m;j++)
                a[i][j]=ll(a[i][j])*p%mod;
            for (int j=1;j<=m;j++)
            {
                if (i+j>=N)
                    break;
                for (int k=1;k<=m;k++)
                    a[i+j][m-j+k]=(a[i+j][m-j+k]-ll(a[i+j][m-j])*a[i][m+k])%mod;
            }
        }
        static int id=0;
        printf("Case %d: %d\n",++id,(ans+mod)%mod);
    }
    return(0);
}

