#include <cstdio>
#include <cstdlib>
struct point
{
   int x,y;
   point(){}
   point(int x,int y):x(x),y(y){}
};
point operator -(point a,point b)
{
   return(point(a.x-b.x,a.y-b.y));
}
double operator *(point a,point b)
{
   return(a.x*b.y-a.y*b.x);
}
point a[60];
int main()
{
   bool check(point,point,point,point);
   while (1)
   {
      int p,q,n;
      scanf("%d%d%d",&p,&q,&n);
      if (!p && !q)
         break;
      for (int i=1;i<=n+1;i++)
         scanf("%d%d",&a[i].x,&a[i].y);
      int ans=n+1;
      for (int i=1;i<=n;i++)
         for (int j=1;j<i;j++)
            ans+=check(a[i],a[i+1],a[j],a[j+1]);
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
bool check(point u1,point u2,point v1,point v2)
{
   if ((u1-v1)*(v2-v1)*((u2-v1)*(v2-v1))>=0)
      return(false);
   if ((v1-u1)*(u2-u1)*((v2-u1)*(u2-u1))>=0)
      return(false);
   return(true);
}
