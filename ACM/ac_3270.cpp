#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
const double epsilon=1e-4;
double x[51],y[51];
int n,a[51][51];
int main()
{
   int get(double,double,double,double);
   int test_id=0;
   double p[51],q[51];
   while (1)
   {
      int m,r,t;
      scanf("%d%d%d%d",&n,&m,&r,&t);
      if (!n && !m && !r && !t)
         break;
      for (int i=1;i<=n;i++)
         scanf("%lf%lf",&x[i],&y[i]);
      for (int i=1;i<=m;i++)
         scanf("%lf%lf",&p[i],&q[i]);
      memset(a,26,sizeof(a));
      for (int i=1;i<=m;i++)
         a[i][i]=0;
      for (int i=1;i<=r;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         a[x][y]=a[y][x]=get(p[x],q[x],p[y],q[y]);
      }
      for (int k=1;k<=m;k++)
         for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
               if (a[i][k]+a[k][j]<a[i][j])
                  a[i][j]=a[i][k]+a[k][j];
      printf("Case %d:\n",++test_id);
      for (int i=1;i<=t;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         if (a[x][y]<20000000)
            printf("%d\n",a[x][y]);
         else
            printf("Impossible\n");
      }
   }
   system("pause");
   return(0);
}
int get(double x1,double y1,double x2,double y2)
{
   int near(double,double);
   int p,q;
   p=near(x1,y1);
   q=near(x2,y2);
   if (p==q)
      return(0);
   if (sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))<epsilon)
      return(1);
   else
   {
      double mid1,mid2;
      mid1=(x1+x2)/2;
      mid2=(y1+y2)/2;
      return(get(x1,y1,mid1,mid2)+get(mid1,mid2,x2,y2));
   }
}
int near(double x0,double y0)
{
   double max=1e10;
   int k;
   for (int i=1;i<=n;i++)
      if (sqrt((x[i]-x0)*(x[i]-x0)+(y[i]-y0)*(y[i]-y0))<max)
      {
         max=sqrt((x[i]-x0)*(x[i]-x0)+(y[i]-y0)*(y[i]-y0));
         k=i;
      }
   return(k);
}
