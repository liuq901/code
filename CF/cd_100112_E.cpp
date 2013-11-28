#include <cstdio>
#include <cmath>
const double pi=acos(-1.0);
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
double X[210],Y[210],len[40010],angle[210][210];
int b[210],a[40010][2];
double sqr(double x)
{
    return(x*x);
}
double dist(int a,int b)
{
    return(sqrt(sqr(X[a]-X[b])+sqr(Y[a]-Y[b])));
}
int n,D,q[40010][2];
bool in[210][210];
double f[210][210];
inline double fix(double x)
{
    if (x<0)
        x+=2*pi;
    if (x>=2*pi)
        x-=2*pi;
    if (x>=pi)
        x=2*pi-x;
    return(x);
}
bool check(double limit)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            f[i][j]=1e10;
    int l,r;
    l=r=0;
    for (int i=b[1];i;i=a[i][1])
    {
        int y=a[i][0];
        f[y][1]=len[i];
        in[y][1]=true;
        q[++r][0]=y,q[r][1]=1;
    }
    while (l!=r)
    {
        l=l==40005?1:l+1;
        int x=q[l][0],pre=q[l][1];
        in[x][pre]=false;
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            if (f[x][pre]+len[i]<f[y][x] && limit>=fix(angle[pre][x]-angle[x][y]))
            {
                f[y][x]=f[x][pre]+len[i];
                if (!in[y][x])
                {
                    in[y][x]=true;
                    r=r==40005?1:r+1;
                    q[r][0]=y,q[r][1]=x;
                }
            }
        }
    }
    for (int i=1;i<=n;i++)
        if (sign(D-f[n][i])>=0)
            return(true);
    return(false);
}
int main()
{
    int m;
    scanf("%d%d%d",&n,&m,&D);
    for (int i=1;i<=n;i++)
        scanf("%lf%lf",&X[i],&Y[i]);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i][0]=y,a[i][1]=b[x],b[x]=i,len[i]=dist(x,y);
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            angle[i][j]=atan2(X[j]-X[i],Y[j]-Y[i]);
    double l=0,r=pi+1;
    bool flag=false;
    for (int T=1;T<=100;T++)
    {
        double mid=(l+r)/2;
        if (check(mid))
        {
            r=mid;
            flag=true;
        }
        else
            l=mid;
    }
    if (!flag)
        printf("Impossible\n");
    else
        printf("%.10f\n",(l+r)/2/pi*180);
    return(0);
}

