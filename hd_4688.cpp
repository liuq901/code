#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline point operator *(const point &a,double b)
{
    return(point(a.x*b,a.y*b));
}
inline point operator /(const point &a,double b)
{
    return(point(a.x/b,a.y/b));
}
inline int sign(double x,double eps=1e-8)
{
    return(x<-eps?-1:x>eps);
}
inline bool operator <(const point &a,const point &b)
{
    return(sign(a.x-b.x)<0 || sign(a.x-b.x)==0 && sign(a.y-b.y)<0);
}
inline bool operator <=(const point &a,const point &b)
{
    return(sign(a.x-b.x)<0 || sign(a.x-b.x)==0 && sign(a.y-b.y)<=0);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
inline bool parellel(const point &a,const point &b)
{
    return(sign(det(a,b))==0);
}
inline point intersect(const point &a,const point &b,const point &c,const point &d)
{
    double s1=det(c-a,b-a),s2=det(d-a,b-a);
    return((c*s2-d*s1)/(s2-s1));
}
double f[210][210];
bool pH[210],pV[210],pA[210][210];
point L[210],R[210],U[210],D[210],p[210],a[210][210];
double cut(int i,int j,int k)
{
    point A=min(p[k],p[k+1]);
    point B=max(p[k],p[k+1]);
    point P=point(-1e9,-1e9);
    point Q=point(1e9,1e9);
    vector <point> lq;
    if (i!=0 && !pA[i-1][k])
        lq.push_back(a[i-1][k]);
    if (j!=0 && !pA[k][j])
        lq.push_back(a[k][j]);
    if (!pH[k])
    {
        lq.push_back(D[k]);
        lq.push_back(U[k]);
    }
    if (!pV[k])
    {
        lq.push_back(L[k]);
        lq.push_back(R[k]);
    }
    for (int i=0;i<lq.size();i++)
    {
        if (lq[i]<=A)
            P=max(P,lq[i]);
        if (B<=lq[i])
            Q=min(Q,lq[i]);
    }
    return(dist(P,Q));
}
int main()
{
    int n,W,H;
    while (scanf("%d%d%d",&n,&W,&H)==3)
    {
        for (int i=1;i<=n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        p[0]=p[n];
        for (int i=1;i<=n;i++)
            p[i+n]=p[i];
        p[2*n+1]=p[1];
        for (int i=0;i<=2*n;i++)
        {
            for (int j=i;j<=2*n;j++)
            {
                f[i][j]=1e100;
                pA[i][j]=parellel(p[i+1]-p[i],p[j+1]-p[j]);
                if (!pA[i][j])
                    a[i][j]=intersect(p[i+1],p[i],p[j+1],p[j]);
            }
            pH[i]=parellel(p[i+1]-p[i],point(1,0));
            if (!pH[i])
            {
                D[i]=intersect(p[i+1],p[i],point(0,0),point(W,0));
                U[i]=intersect(p[i+1],p[i],point(W,H),point(0,H));
            }
            pV[i]=parellel(p[i+1]-p[i],point(0,1));
            if (!pV[i])
            {
                L[i]=intersect(p[i+1],p[i],point(0,0),point(0,H));
                R[i]=intersect(p[i+1],p[i],point(W,H),point(W,0));
            }
        }
        for (int i=2*n;i;i--)
        {
            f[i][i]=0;
            for (int j=i+1;j<=2*n;j++)
            {
                if (i+n-1<j)
                    break;
                for (int k=i;k<j;k++)
                    f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+cut(i,j,k));
            }
        }
        double ans=1e100;
        for (int i=1;i<=n;i++)
            ans=min(ans,f[i][i+n-1]+cut(0,0,i-1));
        printf("%.6f\n",ans);
    }
    return(0);
}

