#include <cstdio>
struct point
{
    double x,y;
    bool in()
    {
        return(scanf("%lf%lf",&x,&y)==2);
    }
};
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
int main()
{
    point a,b,c,d;
    while (a.in() && b.in() && c.in() && d.in())
    {
        bool flag=true;
        if (sign(b.x-c.x)<0 || sign(d.x-a.x)<0)
            flag=false;
        if (sign(b.y-c.y)<0 || sign(d.y-a.y)<0)
            flag=false;
        printf("%s\n",flag?"YES":"NO");
    }
    return(0);
}

