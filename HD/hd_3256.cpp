#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const double eps=1e-5;
int x1[510],y1[510],x2[510],y2[510],s[26000];
double sign(double x)
{
    return(x<-eps?-1:x>eps);
}
int calc(int x)
{
    int p=x/10000*10000;
    while (p<=x)
        p+=10000;
    while (p>x)
        p-=10000;
    return(p);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,upper=-1<<30,lower=1<<30;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            double x,y,xx,yy;
            scanf("%lf%lf%lf%lf",&x,&y,&xx,&yy);
            x1[i]=int(x*10000+sign(x)*eps),x2[i]=int(xx*10000+sign(xx)*eps);
            y1[i]=int(y*10000+sign(y)*eps),y2[i]=int(yy*10000+sign(yy)*eps);
            if (x1[i]>x2[i] || x1[i]==x2[i] && y1[i]>y2[i])
            {
                swap(x1[i],x2[i]);
                swap(y1[i],y2[i]);
            }
            upper=max(upper,calc(x2[i]));
            lower=min(lower,x1[i]);
        }
        int ans=0,t=0;
        memset(s,0,sizeof(s));
        for (int x=upper;x>=lower;x-=10000)
        {
            t++;
            for (int i=1;i<=n;i++)
            {
                if (x<x1[i] || x>x2[i])
                    continue;
                if (x1[i]==x2[i])
                {
                    int p=calc(y2[i]);
                    for (int y=p;y>=y1[i];y-=10000)
                        if (s[y/10000+12000]!=t)
                        {
                            s[y/10000+12000]=t;
                            ans++;
                        }
                    continue;
                }
                ll now=ll(x-x1[i])*(y2[i]-y1[i]);
                if (now%(x2[i]-x1[i])==0)
                {
                    int y=now/(x2[i]-x1[i])+y1[i];
                    if (y%10000==0 && s[y/10000+12000]!=t)
                    {
                        s[y/10000+12000]=t;
                        ans++;
                    }
                }
            }
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

