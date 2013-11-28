#include <cstdio>
#include <cstring>
typedef long long ll;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
};
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y));
}
inline point operator *(const point &a,double b)
{
    return(point(a.x*b,a.y*b));
}
inline point operator /(const point &a,double b)
{
    return(point(a.x/b,a.y/b));
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
point p[1000010],o[1000010];
double area[1000010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        point O(0,0);
        p[0]=p[n];
        point ans(0,0);
        double sum=0;
        for (int i=1;i<=n;i++)
        {
            point o=(p[i]+p[i-1]+O)/3;
            double area=det(p[i],p[i-1]);
            sum+=area;
            ans=ans+o*area;
        }
        ans=ans/sum;
        char s1[100],s2[100];
        sprintf(s1,"%.2f",ans.x);
        sprintf(s2,"%.2f",ans.y);
        if (strcmp(s1,"-0.00")==0)
            sprintf(s1,"0.00");
        if (strcmp(s2,"-0.00")==0)
            sprintf(s2,"0.00");
        printf("%s %s\n",s1,s2);
    }
    return(0);
}

