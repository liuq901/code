#include <cstdio>
#include <cstdlib>
#include <cmath>
struct point
{
   double x,y;
};
point o,p[100001];
double r;
int main()
{
   void work();
   int t;
   scanf("%d",&t);
   while (t--)
      work();
   system("pause");
   return(0);
}
void work()
{
   bool inside(point);
   void put(point,point),put(point,point,point);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%lf%lf",&p[i].x,&p[i].y);
   for (int i=1;i<=n;i++)
   {
      int x=rand()%n+1;
      point t;
      t=p[x],p[x]=p[i],p[i]=t;
   }
   put(p[1],p[2]);
   for (int i=3;i<=n;i++)
      if (!inside(p[i]))
      {
         put(p[1],p[i]);
         for (int j=2;j<i;j++)
            if (!inside(p[j]))
            {
               put(p[i],p[j]);
               for (int k=1;k<j;k++)
                  if (!inside(p[k]))
                     put(p[i],p[j],p[k]);
            }
      }
   printf("%.2lf\n%.2lf %.2lf\n",r,o.x,o.y);
}
bool inside(point p)
{
   double dist(point,point);
   return(dist(p,o)<=r);
}
void put(point a,point b)
{
   double dist(point,point);
   o.x=(a.x+b.x)/2;
   o.y=(a.y+b.y)/2;
   r=dist(a,o);
}
void put(point p1,point p2,point p3)
{
   double dist(point,point);
   double a,b,c,p,q,t1,t2,t3;
   a=dist(p1,p2),b=dist(p1,p3),c=dist(p2,p3);
   p=(a*a+b*b+c*c)/2,q=1/(1/(p-a*a)+1/(p-b*b)+1/(p-c*c));
   t1=q/(p-a*a),t2=q/(p-b*b),t3=q/(p-c*c);
   o.x=(1-t1)/2*p3.x+(1-t2)/2*p2.x+(1-t3)/2*p1.x;
   o.y=(1-t1)/2*p3.y+(1-t2)/2*p2.y+(1-t3)/2*p1.y;
   r=sqrt(p-q)/2;
}
double dist(point a,point b)
{
   return(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}
