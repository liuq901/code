#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int rise=5*3600+37*60,sets=18*3600+17*60;
const double eps=1e-8,pi=acos(-1.0);
struct point
{
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
};
int d[110],h[110];
point l[110],r[110];
void print(double x)
{
    double t=(pi-x)/pi*(sets-rise)+rise;
    int now=int(t+eps);
    printf("%02d:%02d:%02d",now/3600,now%3600/60,now%60);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        int width,height;
        scanf("%d%d%d",&width,&height,&h[1]);
        for (int i=2;i<=n;i++)
            scanf("%d%d",&d[i],&h[i]);
        l[1]=point(0,h[1]*height);
        r[1]=point(width,h[1]*height);
        for (int i=2;i<=n;i++)
        {
            l[i]=point(r[i-1].x+d[i],h[i]*height);
            r[i]=point(l[i].x+width,h[i]*height);
        }
        static int id=0;
        if (id)
            printf("\n");
        printf("Apartment Complex: %d\n",++id);
        while (1)
        {
            int tmp;
            scanf("%d",&tmp);
            if (tmp==0)
                break;
            int y=tmp/100,x=tmp%100;
            printf("\nApartment %d: ",tmp);
            if (x<1 || x>n || y<1 || y>h[x])
                printf("Does not exist\n");
            else
            {
                double lower=pi,upper=0;
                for (int i=1;i<x;i++)
                {
                    point p=r[i],q(l[x].x,height*(y-1));
                    if (p.y<=q.y)
                        continue;
                    lower=min(lower,atan2(p.y-q.y,p.x-q.x));
                }
                for (int i=x+1;i<=n;i++)
                {
                    point p=l[i],q(r[x].x,height*(y-1));
                    if (p.y<=q.y)
                        continue;
                    upper=max(upper,atan2(p.y-q.y,p.x-q.x));
                }
                print(lower);
                printf(" - ");
                print(upper);
                printf("\n");
            }
        }
    }
    return(0);
}

