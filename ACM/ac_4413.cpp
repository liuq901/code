#include <cstdio>
#include <cstdlib>
struct point
{
   double x,y;
   point(){}
   point(double x,double y):x(x),y(y){}
};
point operator +(point a,point b)
{
   return(point(a.x+b.x,a.y+b.y));
}
point operator -(point a,point b)
{
   return(point(a.x-b.x,a.y-b.y));
}
point operator *(double a,point b)
{
   return(point(a*b.x,a*b.y));
}
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      point p,q,r;
      double m1,m2,m3,m4,m5,m6;
      scanf("%lf%lf%lf%lf%lf%lf",&p.x,&p.y,&q.x,&q.y,&r.x,&r.y);
      scanf("%lf%lf%lf%lf%lf%lf",&m1,&m2,&m3,&m4,&m5,&m6);
      double t1,t2,t;
      point a,b,c;
      t1=m3/m4*m1/(m1+m2);
      t2=m6/m5*m2/(m1+m2);
      t=(t1+1)/(t2-t1);
      a=r+t*(r-p);
      t1=m5/m6*m3/(m3+m4);
      t2=m2/m1*m4/(m3+m4);
      t=(t1+1)/(t2-t1);
      b=p+t*(p-q);
      t1=m1/m2*m5/(m5+m6);
      t2=m4/m3*m6/(m5+m6);
      t=(t1+1)/(t2-t1);
      c=q+t*(q-r);
      printf("%.8f %.8f %.8f %.8f %.8f %.8f\n",a.x,a.y,b.x,b.y,c.x,c.y);
   }
   system("pause");
   return(0);
}
