#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct state
{
    double dis;
    int num;
    state(){}
    state(int x,int y,int z):dis(sqrt(double(x*x+y*y))*(1+(z>0))),num(z){}
};
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline bool operator <(const state &a,const state &b)
{
    if (sign(a.dis-b.dis)==0)
        return(a.num>b.num);
    return(a.dis<b.dis);
}
state a[2010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int all,n,m;
        scanf("%d%d",&all,&n);
        for (int i=1;i<=n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i]=state(x,y,-z);
        }
        scanf("%d",&m);
        for (int i=n+1;i<=n+m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i]=state(x,y,z);
        }
        sort(a+1,a+n+m+1);
        bool flag=true;
        for (int i=1;i<=n+m;i++)
        {
            all+=a[i].num;
            if (all<0)
            {
                flag=false;
                break;
            }
        }
        static int id=0;
        printf("Case #%d: %s\n",++id,flag?"Yes":"No");
    }
    return(0);
}

