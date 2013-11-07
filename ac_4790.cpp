#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=110;
const double pi=acos(-1.0);
int K,a[N][N];
inline double sqr(double x)
{
    return(x*x);
}
inline double getlen(double a,double b)
{
    return(sqrt(sqr(a)+sqr(b)-2*a*b*cos(pi/3)));
}
double get(int l1,int r1,int l2,int r2,bool flag)
{
    int l=l1/K*K;
    if (l<=l1)
        l+=K;
    int r=r1/K*K;
    if (r>=r1)
        r-=K;
    if (l>r)
        return(0);
    double lenl,lenr;
    if (!flag)
    {
        lenl=getlen(1.0*(l-l1)/(r1-l1),1.0*(l-l2)/(r2-l2));
        lenr=getlen(1.0*(r-l1)/(r1-l1),1.0*(r-l2)/(r2-l2));
    }
    else
    {
        lenl=getlen(1-1.0*(l-l1)/(r1-l1),1-1.0*(l-l2)/(r2-l2));
        lenr=getlen(1-1.0*(r-l1)/(r1-l1),1-1.0*(r-l2)/(r2-l2));
    }
    int n=(r-l)/K+1;
    return((lenl+lenr)*n/2);
}
double calc(int a,int b,int c,int va,int vb,int vc)
{
    double ret=0;
    if (a==b && a==c)
    {
        if (a%K==0)
            ret+=(a!=va)+(b!=vb)+(c!=vc);
        if (a%K==0 && a!=va && va!=-1)
            ret-=0.5;
        if (a%K==0 && b!=vb && vb!=-1)
            ret-=0.5;
        if (a%K==0 && c!=vc && vc!=-1)
            ret-=0.5;
        return(ret);
    }
    if (a%K==0 && a==b && vc!=-1)
        ret-=0.5;
    if (a%K==0 && a==c && vb!=-1)
        ret-=0.5;
    if (b%K==0 && b==c && va!=-1)
        ret-=0.5;
    if (a>b)
        swap(a,b);
    if (a>c)
        swap(a,c);
    if (b>c)
        swap(b,c);
    ret+=get(a,b,a,c,false)+get(b,c,a,c,true);
    if (b%K==0)
        ret+=getlen(1,1.0*(b-a)/(c-a));
    return(ret);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        int m,d;
        scanf("%d%d%d",&m,&d,&K);
        memset(a,-1,sizeof(a));
        for (int i=1;i<=n;i++)
        {
            int delta=1-i%2;
            for (int j=1;j<=m+delta;j++)
                scanf("%d",&a[i][j]);
        }
        double ans=0;
        for (int i=1;i<n;i++)
        {
            if (i%2==1)
                for (int j=1;j<=m;j++)
                {
                    ans+=calc(a[i][j],a[i+1][j],a[i+1][j+1],a[i+2][j],a[i][j+1],a[i][j-1]);
                    if (j<m)
                        ans+=calc(a[i][j],a[i][j+1],a[i+1][j+1],a[i+1][j+2],a[i+1][j],a[i-1][j+1]);
                }
            else
                for (int j=1;j<=m;j++)
                {
                    ans+=calc(a[i][j],a[i][j+1],a[i+1][j],a[i+1][j+1],a[i+1][j-1],a[i-1][j]);
                    if (j>1)
                        ans+=calc(a[i][j],a[i+1][j-1],a[i+1][j],a[i+2][j],a[i][j+1],a[i][j-1]);
                }
        }
        ans*=d;
        static int id=0;
        printf("Case %d: %.0f\n",++id,ans);
    }
    return(0);
}

