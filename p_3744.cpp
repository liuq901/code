#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
double p,one[4][4];
int a[20];
int main()
{
   double calc(double,int);
   int n;
   while (scanf("%d%lf",&n,&p)==2)
   {
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      one[1][1]=0,one[1][2]=1-p,one[2][1]=1,one[2][2]=p;
      sort(a+1,a+n+1);
      double now=1;
      a[0]=0;
      for (int i=1;i<=n;i++)
      {
         if (a[i]==a[i-1]+1)
         {
            now=0;
            break;
         }
         now=calc(now,a[i]-a[i-1]-1)*(1-p);
      }
      printf("%.7f\n",now);
   }
   system("pause");
   return(0);
}
double b[4][4];
double calc(double x,int n)
{
   void multi(int);
   if (n==1)
      return(x);
   multi(n-1);
   return(x*b[1][1]+p*x*b[2][1]);
}
void multi(int x)
{
   if (x==1)
   {
      memcpy(b,one,sizeof(one));
      return;
   }
   multi(x>>1);
   double c[4][4];
   memset(c,0,sizeof(c));
   for (int i=1;i<=2;i++)
      for (int j=1;j<=2;j++)
         for (int k=1;k<=2;k++)
            c[i][j]+=b[i][k]*b[k][j];
   memcpy(b,c,sizeof(c));
   if (x&1)
   {
      memset(c,0,sizeof(c));
      for (int i=1;i<=2;i++)
         for (int j=1;j<=2;j++)
            for (int k=1;k<=2;k++)
               c[i][j]+=b[i][k]*one[k][j];
      memcpy(b,c,sizeof(c));
   }
}
