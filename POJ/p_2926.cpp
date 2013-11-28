#include <cstdio>
#include <cstdlib>
double max[32],min[32];
int main()
{
   void count(double *),print();
   int n,i;
   double x[10];
   scanf("%d",&n);
   for (i=0;i<32;i++)
   {
      max[i]=-20000000;
      min[i]=20000000;
   }
   for (i=1;i<=n;i++)
   {
      scanf("%lf%lf%lf%lf%lf",&x[1],&x[2],&x[3],&x[4],&x[5]);
      count(x);
   }
   print();
   system("pause");
   return(0);
}
void count(double *x)
{
   int i,j,k;
   double t;
   for (i=0;i<32;i++)
   {
      t=0;
      k=i;
      for (j=1;j<=5;j++)
      {
         if (k%2==0)
            t+=x[j];
         else
            t-=x[j];
         k/=2;
      }
      if (t>max[i])
         max[i]=t;
      if (t<min[i])
         min[i]=t;
   }
}
void print()
{
   int i;
   double ans;
   ans=-20000000;
   for (i=0;i<32;i++)
      if (max[i]-min[i]>ans)
         ans=max[i]-min[i];
   printf("%.2lf\n",ans);
}
