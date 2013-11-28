#include <cstdio>
#include <cstdlib>
int i,n;
double c,d2;
double p[1001],d[1001],con[1001];
int main()
{
   double money(int,int,double);
   scanf("%lf%lf%lf%lf%d",&d[0],&c,&d2,&p[0],&n);
   d[n+1]=d[0];
   for (i=1;i<=n;i++)
      scanf("%lf%lf",&d[i],&p[i]);
   d[0]=0;
   for (i=n;i>=0;i--)
      con[i]=(d[i+1]-d[i])/d2;
   for (i=0;i<=n;i++)
      if (con[i]>c)
      {
         printf("-1");
         goto last;
      }
   printf("%.2lf\n",money(0,n+1,0));
last:
   system("pause");
   return(0);
}
double money(int start,int stop,double rest)
{
   int minp(int,int);
   int k;
   double mon;
   if (stop-start==1)
      mon=((d[stop]-d[start])/d2-rest)*p[start];
   else
   {
      k=minp(start,stop-1);
      if (k!=start)
         mon=money(start,k,rest)+money(k,stop,0);
      else if (d[stop]-d[start]<=d2*c)
         mon=((d[stop]-d[start])/d2-rest)*p[start];
      else
      {
         k=minp(start+1,stop-1);
         if (d[k]-d[start]<=d2*c)
            mon=(c-rest)*p[start]+money(k,stop,c-(d[k]-d[start])/d2);
         else
            mon=money(start,k,rest)+money(k,stop,0);
      }
   }
   return(mon);
}
int minp(int b,int e)
{
   int i,k;
   double temp;
   temp=p[e];
   k=e;
   for (i=e-1;i>=b;i--)
      if (p[i]<temp)
      {
         temp=p[i];
         k=i;
      }
   return(k);
}
