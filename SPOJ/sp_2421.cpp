#include <cstdio>
#include <cstring>
typedef long long ll;
const int mod=1000000007;
int a[20],tmpf[20],tmpg[20],nowf[20],nowg[20],f[1100][20][20][20],g[1100][20][20][20];
bool vis[1100][20][20];
void calc(int state,int n,int from)
{
    if (vis[state][n][from])
        return;
    vis[state][n][from]=true;
    if (n==1)
    {
        int s[30],t[30];
        memset(s,63,sizeof(s));
        memset(t,0,sizeof(t));
        s[from]=0;
        t[from]=1;
        for (int i=from;i<10;i++)
            for (int j=0;j<10;j++)
                if (state>>j&1 || i==j)
                {
                    int x=s[i],y=t[i];
                    if (x+1<s[i+j])
                    {
                        s[i+j]=x+1;
                        t[i+j]=y;
                    }
                    else if (x+1==s[i+j])
                        t[i+j]+=y;
                }
        for (int i=0;i<10;i++)
        {
            f[state][n][from][i]=s[i+10];
            g[state][n][from][i]=t[i+10];
        }
    }
    else
    {
        int nowf[20],nowg[20],tmpf[20],tmpg[20];
        memset(nowf,63,sizeof(nowf));
        memset(nowg,0,sizeof(nowg));
        nowf[from]=0;
        nowg[from]=1;
        for (int i=1;i<=10;i++)
        {
            memset(tmpf,63,sizeof(tmpf));
            memset(tmpg,0,sizeof(tmpg));
            for (int j=0;j<10;j++)
            {
                calc(state|1<<i-1,n-1,j);
                for (int k=0;k<10;k++)
                {
                    int x=nowf[j]+f[state|1<<i-1][n-1][j][k];
                    int y=ll(nowg[j])*g[state|1<<i-1][n-1][j][k]%mod;
                    if (x<tmpf[k])
                    {
                        tmpf[k]=x;
                        tmpg[k]=0;
                    }
                    if (x==tmpf[k])
                        tmpg[k]=(tmpg[k]+y)%mod;
                }
            }
            memcpy(nowf,tmpf,sizeof(tmpf));
            memcpy(nowg,tmpg,sizeof(tmpg));
        }
        for (int i=0;i<10;i++)
        {
            f[state][n][from][i]=nowf[i];
            g[state][n][from][i]=nowg[i];
        }
    }
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        for (int i=1;i<=10;i++)
        {
            a[i]=n%10;
            n/=10;
        }
        int state=0;
        memset(nowf,63,sizeof(nowf));
        memset(nowg,0,sizeof(nowg));
        nowf[1]=0;
        nowg[1]=1;
        for (int i=10;i>1;i--)
        {
            for (int j=1;j<=a[i];j++)
            {
                memset(tmpf,63,sizeof(tmpf));
                memset(tmpg,0,sizeof(tmpg));
                for (int k=0;k<10;k++)
                {
                    calc(state|1<<j-1,i-1,k);
                    for (int l=0;l<10;l++)
                    {
                        int x=nowf[k]+f[state|1<<j-1][i-1][k][l];
                        int y=ll(nowg[k])*g[state|1<<j-1][i-1][k][l]%mod;
                        if (x<tmpf[l])
                        {
                            tmpf[l]=x;
                            tmpg[l]=0;
                        }
                        if (x==tmpf[l])
                            tmpg[l]=(tmpg[l]+y)%mod;
                    }
                }
                memcpy(nowf,tmpf,sizeof(tmpf));
                memcpy(nowg,tmpg,sizeof(tmpg));
            }
            state|=1<<a[i];
        }
        for (int i=0;i<10;i++)
            for (int j=0;i+j<10;j++)
                if (state>>j&1 || i==j)
                {
                    int x=nowf[i],y=nowg[i];
                    if (x+1<nowf[i+j])
                    {
                        nowf[i+j]=x+1;
                        nowg[i+j]=0;
                    }
                    if (x+1==nowf[i+j])
                        nowg[i+j]=(nowg[i+j]+y)%mod;
                }
        if (nowg[a[1]]==0)
            printf("IMPOSSIBLE\n");
        else
            printf("%d %d\n",nowf[a[1]],nowg[a[1]]);
    }
    return(0);
}

