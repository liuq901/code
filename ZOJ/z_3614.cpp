#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=310;
int log[N],a[N][N],f[10][N][10][N];
ll s1[N][N],s2[N][N];
template <class T> T sqr(T x)
{
    return(x*x);
}
void init(int n,int m)
{
    for (int i1=0;i1<=log[n];i1++)
        for (int j1=1;j1<=n;j1++)
        {
            if (j1+(1<<i1)-1>n)
                break;
            for (int i2=0;i2<=log[m];i2++)
                for (int j2=1;j2<=m;j2++)
                {
                    if (j2+(1<<i2)-1>m)
                        break;
                    if (i1==0 && i2==0)
                        f[i1][j1][i2][j2]=a[j1][j2];
                    else if (i2==0)
                        f[i1][j1][i2][j2]=max(f[i1-1][j1][i2][j2],f[i1-1][j1+(1<<i1-1)][i2][j2]);
                    else
                        f[i1][j1][i2][j2]=max(f[i1][j1][i2-1][j2],f[i1][j1][i2-1][j2+(1<<i2-1)]);
                }
        }
}
int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
int get(int l1,int l2,int r1,int r2)
{
    int t1=log[r1-l1+1],t2=log[r2-l2+1];
    return(max(max(f[t1][l1][t2][l2],f[t1][l1][t2][r2-(1<<t2)+1]),max(f[t1][r1-(1<<t1)+1][t2][l2],f[t1][r1-(1<<t1)+1][t2][r2-(1<<t2)+1])));
}
ll range(ll s[N][N],int x1,int y1,int x2,int y2)
{
    return(s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]);
}
int main()
{
    log[1]=0;
    for (int i=2;i<=300;i++)
    {
        log[i]=log[i-1];
        if (!(i&i-1))
            log[i]++;
    }
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
                s1[i][j]=s1[i][j-1]+s1[i-1][j]-s1[i-1][j-1]+a[i][j];
                s2[i][j]=s2[i][j-1]+s2[i-1][j]-s2[i-1][j-1]+sqr(a[i][j]);
            }
        init(n,m);
        int Q;
        static int id=0;
        printf("Case %d:\n",++id);
        scanf("%d",&Q);
        while (Q--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            int tot=u*v-1,x0,y0;
            u--,v--;
            double ans=1e10;
            for (int i=1;i<=n-u;i++)
                for (int j=1;j<=m-v;j++)
                {
                    int big=get(i,j,i+u,j+v);
                    double x=(range(s2,i,j,i+u,j+v)-sqr(big))/double(tot);
                    double y=sqr((range(s1,i,j,i+u,j+v)-big)/double(tot));
                    if (sign(x-y-ans)<0)
                        ans=x-y,x0=i,y0=j;
                }
            printf("(%d, %d), %.2f\n",x0,y0,ans);
        }
    }
    return(0);
}

