#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void in()
    {
        scanf("%lf%lf",&x,&y);
    }
};
inline point operator +(const point &a,const point &b)
{
    return(point(a.x+b.x,a.y+b.y));
}
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
inline double dot(const point &a,const point &b)
{
    return(a.x*b.x+a.y*b.y);
}
inline double det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline int side(const point &p,const point &a,const point &b)
{
    return(sign(det(b-a,p-a)));
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
inline double area(const pair <point,point> &a,const pair <point,point> &b)
{
    return(((b.first.y-a.first.y)+(b.second.y-a.second.y))*(a.second.x-a.first.x)/2);
}
point a[60][10];
bool vis[60];
double ans[60];
void calc(double l,double r,int n)
{
    if (sign(l-r)==0)
        return;
    vector <pair <pair <point,point>,int> > lq;
    for (int i=1;i<=n;i++)
    {
        if (vis[i])
            continue;
        for (int j=1;j<=3;j++)
            for (int k=j+1;k<=3;k++)
            {
                point A=a[i][j],B=a[i][k],C=a[i][6-j-k];
                if (sign(A.x-B.x)==0)
                    continue;
                if (B<A)
                    swap(A,B);
                if (sign(r-A.x)<=0 || sign(l-B.x)>=0)
                    continue;
                point P,Q;
                P=intersect(A,B,point(l,0),point(l,1));
                Q=intersect(A,B,point(r,0),point(r,1));
                if (side(A+point(0,1),A,B)==side(C,A,B))
                    lq.push_back(make_pair(make_pair(P,Q),1));
                else
                    lq.push_back(make_pair(make_pair(P,Q),-1));
            }
    }
    sort(lq.begin(),lq.end());
    int cnt=1;
    for (int i=1;i<lq.size();i++)
    {
        ans[cnt]+=area(lq[i-1].first,lq[i].first);
        cnt+=lq[i].second;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        vector <double> lq;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=3;j++)
            {
                a[i][j].in();
                lq.push_back(a[i][j].x);
            }
            vis[i]=parellel(a[i][3]-a[i][1],a[i][2]-a[i][1]);
            a[i][0]=a[i][3];
        }
        for (int i=1;i<=n;i++)
        {
            if (vis[i])
                continue;
            for (int j=i+1;j<=n;j++)
            {
                if (vis[j])
                    continue;
                for (int k=1;k<=3;k++)
                    for (int l=1;l<=3;l++)
                    {
                        if (parellel(a[i][k]-a[i][k-1],a[j][l]-a[j][l-1]))
                            continue;
                        point tmp=intersect(a[i][k],a[i][k-1],a[j][l],a[j][l-1]);
                        if (sign(dot(tmp-a[i][k],tmp-a[i][k-1]))<=0 && sign(dot(tmp-a[j][l],tmp-a[j][l-1]))<=0)
                            lq.push_back(tmp.x);
                    }
            }
        }
        memset(ans,0,sizeof(ans));
        sort(lq.begin(),lq.end());
        for (int i=1;i<lq.size();i++)
            calc(lq[i-1],lq[i],n);
        for (int i=1;i<=n;i++)
            printf("%.10f\n",ans[i]);
    }
    return(0);
}

