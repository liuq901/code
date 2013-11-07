#include <cstdio>
#include <cmath>
const double pi=acos(-1.0);
struct point
{
    double x,y;
    void in()
    {
        scanf("%lf%lf",&x,&y);
    }
};
point a[30];
int n;
double calc(int x,int y)
{
    double ret=atan2(a[y].y-a[x].y,a[y].x-a[x].x);
    if (ret<0 || ret==pi)
        ret=calc(y,x);
    return(ret);
}
void next(int &pre,int &now,double &angle)
{
    int k;
    double mi=1e10;
    for (int i=1;i<=n;i++)
    {
        if (i==now || i==pre)
            continue;
        double here=calc(i,now)-angle;
        if (here<0)
            here+=2*pi;
        if (here<mi)
            mi=here,k=i;
    }
    pre=now;
    now=k;
    angle=calc(k,pre);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int id,Q,now;
        double angle;
        scanf("%d%d%d%d%lf",&id,&n,&Q,&now,&angle);
        angle=angle/180.0*pi;
        printf("%d",id);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&id);
            a[id].in();
        }
        int pre=0;
        while (Q--)
        {
            next(pre,now,angle);
            printf(" %d",now);
        }
        printf("\n");
    }
    return(0);
}

