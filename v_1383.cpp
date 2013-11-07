#include <cstdio>
#include <cstdlib>
int n,m,max;
int main()
{
   void f1(),f2();
   scanf("%d%d",&n,&m);
   if (m%2!=0)
      f1();
   else
      f2();
   printf("%d\n",max);
   system("pause");
   return(0);
}
void f1()
{
   int i;
   max=0;
   for (i=1;i<=n;i++)
      if (i%m<=m/2 && i%m!=0)
         max++;
   max++;
}
void f2()
{
   int i,b1,b2;
   b1=b2=1;
   max=0;
   for (i=1;i<=n;i++)
   {
      if (b1 && i%m==0)
      {
         max++;
         b1=0;
         continue;
      }
      if (b2 && i%m==m/2)
      {
         max++;
         b2=0;
         continue;
      }
      if (i%m!=0 && i%m<m/2)
         max++;
   }
}
