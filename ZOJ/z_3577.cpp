#include <cstdio>
const double eps=1e-8;
double damage[100010];
inline double calc(double l,double r,int n)
{
    return((l+r)*n/2);
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        double h,hp,e,a;
        scanf("%*lf%lf%lf%lf%lf",&h,&hp,&e,&a);
        double best=0;
        int ans;
        for (int i=1;i<=n;i++)
            damage[i]=damage[i-1]+i*hp/a;
        for (int i=1;i<=n;i++)
        {
            int m=n-i;
            double now;
            if (m*h<=a)
            {
                double alive=hp/(a-m*h),cost=alive*h;
                int t=int(e/cost+eps);
                if (t>=i)
                    now=calc(i*alive,1,i);
                else
                {
                    now=calc(i*alive,(i-t+1)*alive,t);
                    double magic=e-cost*t;
                    int rest=i-t;
                    now+=(hp+magic*m)/a*rest+damage[rest-1];
                }
            }
            else
                now=(hp+e*m)/a*i+damage[i-1];
            if (now>best)
            {
                best=now;
                ans=i;
            }
        }
        printf("%d\n",ans);
    }
    return(0);
}

