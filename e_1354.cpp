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
int n,x[101],y[101];
void work()
{
   bool did();
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d%d",&x[i],&y[i]);
   if (!did())
   {
      printf("NIE\n");
      return;
   }
   for (int i=1;i<=n;i++)
   {
      int t;
      t=x[i],x[i]=y[i],y[i]=t;
   }
   if (!did())
   {
      printf("NIE\n");
      return;
   }
   printf("TAK\n");
}
bool did()
{
   int gcd(int,int);
   int g=0;
   for (int i=1;i<=n;i++)
   {
      if (!x[i])
      {
         g=gcd(abs(y[i]),g);
         continue;
      }
      for (int j=1;j<=n;j++)
      {
         if (!x[j])
            continue;
         int t,len,p1,p2;
         t=gcd(abs(x[i]),abs(x[j]));
         p1=(x[i]*x[j]-x[j]*x[i])/t;
         p2=(y[i]*x[j]-y[j]*x[i])/t;
         len=int(sqrt(p1*p1+p2*p2));
         g=gcd(len,g);
      }
   }
   if (g!=1)
      return(false);
   bool flag1,flag2;
   flag1=flag2=false;
   for (int i=1;i<=n;i++)
   {
      if (!x[i])
      {
         if (y[i]>0)
            flag1=true;
         if (y[i]<0)
            flag2=true;
         continue;
      }
      for (int j=1;j<=n;j++)
      {
         if (!x[j])
            continue;
         int p,q;
         p=x[i]*abs(x[j])+x[j]*abs(x[i]);
         q=y[i]*abs(x[j])+y[j]*abs(x[i]);
         if (!p && q>0)
            flag1=true;
         if (!p && q<0)
            flag2=true;
      }
   }
   return(flag1 && flag2);
}
int gcd(int x,int y)
{
   return(y?gcd(y,x%y):x);
}
