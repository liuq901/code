#include <cstdio>
#include <cstdlib>
#include <cmath>
double ans,x[100001],y[100001];
int n;
int main()
{
   void sort(int,int,double *,double *),work();
   while (1)
   {
      scanf("%d",&n);
      if (!n)
         break;
      for (int i=1;i<=n;i++)
         scanf("%lf%lf",&x[i],&y[i]);
      ans=1e10;
      sort(1,n,x,y);
      work();
      sort(1,n,y,x);
      work();
      printf("%.2lf\n",ans/2);
   }
   system("pause");
   return(0);
}
void sort(int l,int r,double *a,double *b)
{
   int i,j;
   double x,t;
   i=l,j=r;
   x=a[l+r>>1];
   while (i<=j)
   {
      while (a[i]<x)
         i++;
      while (a[j]>x)
         j--;
      if (i<=j)
      {
         t=a[i],a[i]=a[j],a[j]=t;
         t=b[i],b[i]=b[j],b[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r,a,b);
   if (l<j)
      sort(l,j,a,b);
}
void work()
{
   for (int i=1;i<=n;i++)
   {
      int p=i-26;
      if (p<=0)
         p=1;
      for (int j=p;j<=i-1;j++)
      {
         double t=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
         if (t<ans)
            ans=t;
      }
   }
}
