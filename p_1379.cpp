#include <cstdio>
#include <cstdlib>
#include <cmath>
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
int t,x[1001],y[1001];
void work()
{
   double dis(double,double);
   int n,m;
   scanf("%d%d%d",&n,&m,&t);
   for (int i=1;i<=t;i++)
      scanf("%d%d",&x[i],&y[i]);
   int p=25;
   double a[p+1][3];
   srand(t);
   for (int i=1;i<=p;i++)
   {
      a[i][0]=(rand()%100+1)/100.001*n;
      a[i][1]=(rand()%100+1)/100.001*m;
      a[i][2]=dis(a[i][0],a[i][1]);
   }
   double delta;
   if (n>m)
      delta=n;
   else
      delta=m;
   delta/=sqrt(double(t));
   double epsilon=0.001;
   int l=50;
   while (delta>epsilon)
   {
      for (int i=1;i<=p;i++)
         for (int j=1;j<=l;j++)
         {
            double t1=(rand()%100+1)/100.001*delta;
            double t2=sqrt(delta*delta-t1*t1);
            if (rand()%2)
               t1*=-1;
            if (rand()%2)
               t2*=-1;
            if (a[i][0]+t1>n || a[i][0]+t1<0 || a[i][1]+t2>m || a[i][1]+t2<0)
               continue;
            double tmp=dis(a[i][0]+t1,a[i][1]+t2);
            if (tmp>a[i][2])
               a[i][0]+=t1,a[i][1]+=t2,a[i][2]=tmp;
         }
      delta*=0.8;
   }
   int k=0;
   double max=0;
   for (int i=1;i<=p;i++)
      if (a[i][2]>max)
      {
         max=a[i][2];
         k=i;
      }
   printf("The safest point is (%.1lf, %.1lf).\n",a[k][0],a[k][1]);
}
double dis(double a,double b)
{
   double min=1e10;
   for (int i=1;i<=t;i++)
   {
      double tmp=sqrt((a-x[i])*(a-x[i])+(b-y[i])*(b-y[i]));
      if (tmp<min)
         min=tmp;
   }
   return(min);
}
