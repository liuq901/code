#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int ans[10][10][10][10],q[2000000],d[2000000];
bool vis[2000000];
bool near(int b[5][5],int x0,int y0,int K)
{
    bool f[5]={0};
    for (int i=0;i<4;i++)
    {
        int x=x0+c[i][0],y=y0+c[i][1];
        f[b[x][y]]=true;
    }
    for (int i=1;i<K;i++)
        if (!f[i])
            return(false);
    return(true);
}
int state(int b[5][5])
{
    int ret=0,now=1;
    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++)
        {
            ret+=b[i][j]*now;
            now*=5;
        }
    return(ret);
}
void init()
{
    int l,r;
    q[l=r=1]=0;
    vis[0]=true;
    d[0]=0;
    memset(ans,63,sizeof(ans));
    while (l<=r)
    {
        int b[5][5]={0},x=q[l++],tmp=x,e[5]={0};
        for (int i=1;i<=3;i++)
            for (int j=1;j<=3;j++)
            {
                b[i][j]=tmp%5;
                tmp/=5;
                e[b[i][j]]++;
            }
        ans[e[1]][e[2]][e[3]][e[4]]=min(ans[e[1]][e[2]][e[3]][e[4]],d[x]);
        for (int i=1;i<=3;i++)
            for (int j=1;j<=3;j++)
            {
                int tmp=b[i][j];
                for (int k=1;k<5;k++)
                    if (near(b,i,j,k))
                    {
                        b[i][j]=k;
                        int y=state(b);
                        if (!vis[y])
                        {
                            vis[y]=true;
                            q[++r]=y;
                            d[y]=d[x]+1;
                        }
                    }
                b[i][j]=tmp;
            }
    }
}
int w[10];
int calc(int W)
{
    int ret=1<<30;
    for (int i=0;i<10;i++)
        for (int j=0;j<10-i;j++)
            for (int k=0;k<10-i-j;k++)
                for (int l=0;l<10-i-j-k;l++)
                    if (i*w[1]+j*w[2]+k*w[3]+l*w[4]>=W)
                        ret=min(ret,ans[i][j][k][l]);
    if (ret>10000)
        ret=-1;
    return(ret);
}
int main()
{
    init();
    int W;
    while (scanf("%d%d%d%d%d",&w[1],&w[2],&w[3],&w[4],&W)==5)
    {
        int ans=calc(W);
        static int id=0;
        printf("Case %d: ",++id);
        if (ans==-1)
            printf("Impossible\n");
        else
            printf("%d\n",ans);
    }
    return(0);
}

