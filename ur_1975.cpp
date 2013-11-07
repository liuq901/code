#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
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
inline int sign(double x,double eps=1e-6)
{
    return(x<-eps?-1:x>eps);
}
inline bool operator <(const point &a,const point &b)
{
    return(sign(a.x-b.x)<0 || sign(a.x-b.x)==0 && (sign(a.y-b.y)<0 || sign(a.y-b.y)==0 && sign(a.z-b.z)<0));
}
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y+a.z*b.z);
}
inline point det(const point &a,const point &b)
{
    return(point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x));
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)+sqr(a.z-b.z)));
}
point p[210],q[210];
double X[10][10],Y[10][10],a[10][10];
void get(double a[10][10],int id,const point &p)
{
    a[1][id]=p.x,a[2][id]=p.y,a[3][id]=p.z;
}
point rotate(const point &p)
{
    return(point(a[1][1]*p.x+a[1][2]*p.y+a[1][3]*p.z,a[2][1]*p.x+a[2][2]*p.y+a[2][3]*p.z,a[3][1]*p.x+a[3][2]*p.y+a[3][3]*p.z));
}
double c[10][10];
void matrix_rev(double a[10][10])
{
    for (int i=1;i<=3;i++)
    {
        for (int j=1;j<=3;j++)
            c[i][j]=a[i][j];
        for (int j=1;j<=3;j++)
            c[i][j+3]=0;
        c[i][i+3]=1;
    }
    double *b[10];
    for (int i=1;i<=3;i++)
        b[i]=c[i];
    for (int i=1;i<=3;i++)
    {
        for (int j=i;j<=3;j++)
            if (fabs(b[j][i])>fabs(b[i][i]))
                swap(b[i],b[j]);
        for (int j=1;j<=3;j++)
        {
            if (i==j)
                continue;
            double rate=b[j][i]/b[i][i];
            for (int k=1;k<=6;k++)
                b[j][k]-=b[i][k]*rate;
        }
        double rate=b[i][i];
        for (int j=1;j<=6;j++)
            b[i][j]/=rate;
    }
    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++)
            a[i][j]=b[i][j+3];
}
void calc()
{
    matrix_rev(X);
    memset(a,0,sizeof(a));
    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++)
            for (int k=1;k<=3;k++)
                a[i][j]+=Y[i][k]*X[k][j];
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        p[i].in();
    sort(p+1,p+n+1);
    int ans=0,id;
    for (int i=2;i<=n;i++)
        if (sign(p[1].x+p[i].x)!=0 || sign(p[1].y+p[i].y)!=0 || sign(p[1].z+p[i].z)!=0)
        {
            id=i;
            break;
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            if (i==j)
                continue;
            if (sign(dot(p[1],p[id])-dot(p[i],p[j]))!=0)
                continue;
            get(X,1,p[1]);
            get(X,2,p[id]);
            get(X,3,det(p[1],p[id]));
            get(Y,1,p[i]);
            get(Y,2,p[j]);
            get(Y,3,det(p[i],p[j]));
            calc();
            for (int k=1;k<=n;k++)
                q[k]=rotate(p[k]);
            sort(q+1,q+n+1);
            bool flag=true;
            for (int k=1;k<=n;k++)
                if (sign(dist(p[k],q[k]))!=0)
                {
                    flag=false;
                    break;
                }
            ans+=flag;
        }
    printf("%d\n",ans);
    return(0);
}

