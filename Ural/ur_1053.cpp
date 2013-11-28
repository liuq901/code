#include <cstdio>
#include <cstdlib>
int main()
{
   int gcd(int,int);
   int n;
   scanf("%d",&n);
   if (n==1)
   {
      int x;
      scanf("%d",&x);
      printf("%d\n",x);
   }
   else
   {
      int x0,y0;
      scanf("%d%d",&x0,&y0);
      int p=gcd(x0,y0);
      for (int i=3;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         p=gcd(p,x);
      }
      printf("%d\n",p);
   }
   system("pause");
   return(0);
}
int gcd(int a,int b)
{
   return(b?gcd(b,a%b):a);
}
