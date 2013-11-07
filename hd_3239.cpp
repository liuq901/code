#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=10;
const double eps=1e-8,PI=acos(-1.0);
int sign(double x)
{
    if (x<-eps)
        return(-1);
    return(x>eps);
}
struct point
{
    double x,y;
    point()
    {
        x=y=0;
    }
    point(double x,double y):x(x),y(y){}
    point operator +(const point &a) const
    {
        return(point(x+a.x,y+a.y));
    }
    point operator -(const point &a) const
    {
        return(point(x-a.x,y-a.y));
    }
    point operator *(double k) const
    {
        return(point(x*k,y*k));
    }
    point operator /(double k) const
    {
        return(point(x/k,y/k));
    }
    double len() const
    {
        return(sqrt(len2()));
    }
    double len2() const
    {
        return(x*x+y*y);
    }
};
double cross(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
struct Tcir
{
    point o;
    double r;
    Tcir(){}
    Tcir(const point &o,double r):o(o),r(r){}
};
struct Tevent
{
    point p;
    double ang;
    int add;
    Tevent(){}
    Tevent(const point &p,double ang,int add):p(p),ang(ang),add(add){}
    bool operator <(const Tevent &a) const
    {
        return(ang<a.ang);
    }
};
Tevent eve[maxn*2];
int E,cnt;
double sqr(double x)
{
    return(x*x);
}
void circleCrossCircle(const Tcir &a,const Tcir &b)
{
    double l=(a.o-b.o).len2();
    double s=((a.r-b.r)*(a.r+b.r)/l+1)*0.5;
    double t=sqrt(-(l-sqr(a.r-b.r))*(l-sqr(a.r+b.r))/(l*l*4));
    point dir=b.o-a.o;
    point Ndir=point(-dir.y,dir.x);
    point aa=a.o+dir*s+Ndir*t;
    point bb=a.o+dir*s-Ndir*t;
    double A=atan2(aa.y-a.o.y,aa.x-a.o.x);
    double B=atan2(bb.y-a.o.y,bb.x-a.o.x);
    eve[E++]=Tevent(bb,B,1);
    eve[E++]=Tevent(aa,A,-1);
    if (B>A)
        cnt++;
}
bool contain(double x1,double y1,double r1,double x2,double y2,double r2)
{
    return(sign(r1-r2)>=0 && sign(sqr(x1-x2)+sqr(y1-y2)-sqr(r1-r2))<=0);
}
bool disjoint(double x1,double y1,double r1,double x2,double y2,double r2)
{
    return(sign(sqr(x1-x2)+sqr(y1-y2)-sqr(r1+r2))>=0);
}
bool same(double x1,double y1,double r1,double x2,double y2,double r2)
{
    return(sign(x1-x2)==0 && sign(y1-y2)==0 && sign(r1-r2)==0);
}
bool g[maxn][maxn],Overlap[maxn][maxn];
double Area[maxn],cX[maxn],cY[maxn],cR[maxn],X[maxn],Y[maxn],R[maxn];
Tcir c[maxn];
int C;
int main()
{
    while (1)
    {
        int x1,x2,x3,x4,y1,y2,y3,y4;
        scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        if (!x1 && !x2 && !x3 && !x4 && !y1 && !y2 && !y3 && !y4)
            break;
        point pA(x1,y1),pB(x2,y2),pC(x3,y3),pD(x4,y4);
        c[0]=Tcir((pA+pC)/2,(pA-pC).len()/2);
        c[1]=Tcir((pA+pD)/2,(pA-pD).len()/2);
        c[2]=Tcir((pB+pC)/2,(pB-pC).len()/2);
        c[3]=Tcir((pB+pD)/2,(pB-pD).len()/2);
        for (int i=0;i<4;i++)
        {
            X[i]=c[i].o.x;
            Y[i]=c[i].o.y;
            R[i]=c[i].r;
        }
        C=4;
        int tmp=0;
        for (int i=0;i<C;i++)
        {
            cX[i]=X[tmp];
            cY[i]=Y[tmp];
            cR[i]=R[tmp];
            tmp++;
            bool found=false;
            for (int j=0;j<i;j++)
                if (same(cX[i],cY[i],cR[i],cX[j],cY[j],cR[j]))
                {
                    found=true;
                    break;
                }
            if (found)
            {
                i--;
                C--;
                continue;
            }
            c[i]=Tcir(point(cX[i],cY[i]),cR[i]);
        }
        for (int i=0;i<=C;i++)
            Area[i]=0;
        for (int i=0;i<C;i++)
            for (int j=0;j<C;j++)
                Overlap[i][j]=contain(cX[i],cY[i],cR[i],cX[j],cY[j],cR[j]);
        for (int i=0;i<C;i++)
            for (int j=0;j<C;j++)
                g[i][j]=!(Overlap[i][j] || Overlap[j][i] || disjoint(cX[i],cY[i],cR[i],cX[j],cY[j],cR[j]));
        for (int i=0;i<C;i++)
        {
            E=0;
            cnt=1;
            for (int j=0;j<C;j++)
                if (j!=i && Overlap[j][i])
                    cnt++;
            for (int j=0;j<C;j++)
                if (i!=j && g[i][j])
                    circleCrossCircle(c[i],c[j]);
            if (E==0)
                Area[cnt]+=PI*sqr(c[i].r);
            else
            {
                double counts=0;
                sort(eve,eve+E);
                eve[E]=eve[0];
                for (int j=0;j<E;j++)
                {
                    cnt+=eve[j].add;
                    Area[cnt]+=cross(eve[j].p,eve[j+1].p)*0.5;
                    double theta=eve[j+1].ang-eve[j].ang;
                    if (theta<0)
                        theta+=PI*2;
                    Area[cnt]+=theta*sqr(c[i].r)*0.5-sin(theta)*sqr(c[i].r)*0.5;
                }
            }
        }
        static int id=0;
        printf("Case %d: %.3f\n\n",++id,Area[1]-Area[C]);
    }
    return(0);
}

