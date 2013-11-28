#include <cstdio>
#include <cmath>
#define SQR(x) ((x)*(x))
const double eps=1e-8;
struct point
{
    double x,y,z;
    point(){}
    point(double x,double y,double z):x(x),y(y),z(z){}
    void in()
    {
        scanf("%lf%lf%lf",&x,&y,&z);
    }
};
point operator +(point a,point b)
{
    return(point(a.x+b.x,a.y+b.y,a.z+b.z));
}
point operator -(point a,point b)
{
    return(point(a.x-b.x,a.y-b.y,a.z-b.z));
}
double operator *(point a,point b)
{
    return(a.x*b.x+a.y*b.y+a.z*b.z);
}
point operator *(point a,double b)
{
    return(point(a.x*b,a.y*b,a.z*b));
}
double dist(point a,point b)
{
    return(sqrt(SQR(a.x-b.x)+SQR(a.y-b.y)+SQR(a.z-b.z)));
}
point a[10010];
double r[10010];
bool in(int id,point P)
{
    return(dist(a[id],P)-r[id]<-eps);
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        for (int i=1;i<=n;i++)
        {
            a[i].in();
            scanf("%lf",&r[i]);
        }
        static int id=0;
        if (id)
            printf("\n");
        printf("Case %d:\n",++id);
        int Q;
        scanf("%d",&Q);
        point O(0,0,0);
        while (Q--)
        {
            point P;
            P.in();
            bool flag=true;
            for (int i=1;i<=n;i++)
            {
                double t=(a[i]-O)*(P-O)/SQR(P-O);
                point T=O+(P-O)*t;
                if ((O-T)*(P-T)<eps && dist(a[i],T)-r[i]<-eps || in(i,P) && !in(i,O) || !in(i,P) && in(i,O))
                {
                    flag=false;
                    break;
                }
            }
            printf("%s\n",flag?"Yes":"No");
        }
    }
    return(0);
}

