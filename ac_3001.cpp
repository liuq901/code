#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps=1e-8;
inline int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
int a[30][2];
inline bool range(double lower,double x,double upper)
{
    return(sign(x-lower)>=0 && sign(x-upper)<0);
}
bool Catch(int n,double x)
{
    bool f1,f2;
    f1=f2=false;
    for (int i=1;i<=n;i++)
    {
        double p=(i-1)*3+1;
        for (int j=0;j<=1;j++)
        {
            if (a[i][j]==-1 && (range(0,x-p,0.5) || range(0,p-x,3)))
                f1=true;
            if (a[i][j]==1 && (range(0,x-p,3) || range(0,p-x,0.5)))
                f2=true;
        }
    }
    return(f1 && f2);
}
double calc(double p,double x)
{
    double t=2*x/p;
    return(p/2*(sqrt(t*(1+t))+log(sqrt(t)+sqrt(1+t))));
}
inline double sqr(double x)
{
    return(x*x);
}
double work(double u,double v,double tmp,double d)
{
    u-=tmp+1,v-=tmp+1;
    double a=sqr((sqrt(u)+sqrt(v))/d);
    return(calc(0.5/a,u)+calc(0.5/a,v));
}
int main()
{
    while (1)
    {
        int L,R;
        double d;
        scanf("%d%d%lf",&L,&R,&d);
        if (L==0 && R==0 && sign(d)==0)
            break;
        memset(a,0,sizeof(a));
        for (int i=1;i<=L;i++)
        {
            char s[10];
            scanf("%s",s);
            a[i][0]=s[0]=='C'?-1:s[0]=='B';
        }
        for (int i=1;i<=R;i++)
        {
            char s[10];
            scanf("%s",s);
            a[i][1]=s[0]=='C'?-1:s[0]=='B';
        }
        int n=max(L,R);
        double bridge=-1,bottom=1,up=(min(L,R)-1)*3-1;
        for (double i=bottom;sign(i-up)<=0;i+=0.5)
            if (!Catch(n,i))
            {
                bridge=i;
                break;
            }
        static int id=0;
        if (id)
            printf("\n");
        printf("Case %d: ",++id);
        if (bridge<0)
            printf("impossible\n");
        else
            printf("%.3f\n",work((L-1)*3+1,(R-1)*3+1,bridge,d));
    }
    return(0);
}

