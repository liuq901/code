#include <cstdio>
const int mod=1000000007;
const int c[4][4]={{0,1,2,3},{1,2,3,0},{2,3,0,1},{3,0,1,2}};
int three[15],t[1600000],f[2][1600000],q[2][1600000],a[20][20][4];
inline int toint(char ch)
{
    return(ch=='C'?2:ch=='R');
}
inline int get(int state,int x)
{
    return(state/three[x]%3);
}
int main()
{
    three[0]=1;
    for (int i=1;i<=14;i++)
        three[i]=three[i-1]*3;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
            {
                char buf[10];
                scanf("%s",buf);
                for (int k=0;k<4;k++)
                    a[i][j][k]=toint(buf[k]);
            }
        for (int i=0;i<three[m+1];i++)
            t[i]=0;
        q[0][0]=1,q[0][1]=0,f[0][0]=1;
        int x=0,y=0,dep=0,ans=0;
        while (1)
        {
            dep++;
            int u=dep&1,v=1-u;
            q[u][0]=0;
            for (int i=1;i<=q[v][0];i++)
            {
                int old=q[v][i];
                for (int k=0;k<4;k++)
                    if ((y==0 || get(old,y)==a[x][y][c[k][3]]) && (x==0 || get(old,y+1)==a[x][y][c[k][0]]))
                    {
                        int now=old/three[y+2]*three[y+2]+old%three[y]+a[x][y][c[k][1]]*three[y+1]+a[x][y][c[k][2]]*three[y];
                        if (t[now]==dep)
                            f[u][now]=(f[u][now]+f[v][old])%mod;
                        else
                        {
                            t[now]=dep;
                            f[u][now]=f[v][old];
                            q[u][++q[u][0]]=now;
                        }
                    }
            }
            y++;
            if (y==m)
            {
                x++;
                y=0;
                dep++;
                q[v][0]=0;
                for (int i=1;i<=q[u][0];i++)
                {
                    int old=q[u][i];
                    int now=old%three[m]*3;
                    if (t[now]==dep)
                        f[v][now]=(f[v][now]+f[u][old])%mod;
                    else
                    {
                        t[now]=dep;
                        f[v][now]=f[u][old];
                        q[v][++q[v][0]]=now;
                    }
                }
            }
            if (x==n)
            {
                for (int i=1;i<=q[u][0];i++)
                {
                    int now=q[u][i];
                    ans=(ans+f[u][now])%mod;
                }
                break;
            }
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

