#include <cstdio>
#include <cstdlib>
#include <cmath>
int n;
int main()
{
   void check(int,int);
   scanf("%d",&n);
   if (n==1)
   {
      printf("2\n");
      printf("3\n");
      printf("5\n");
      printf("7\n");
   }
   else
   {
      check(1,2);
      check(1,3);
      check(1,5);
      check(1,7);
   }
   system("pause");
   return(0);
}
void check(int x,int m)
{
   int ss(int);
   int t,i;
   for (i=1;i<=5;i++)
   {
      t=m*10+2*i-1;
      if (ss(t))
         if (x==n-1)
            printf("%d\n",t);
         else
            check(x+1,t);
   }
}
int ss(int x)
{
   int i,flag;
   flag=1;
   for (i=2;i<sqrt(x)+1;i++)
      if (x%i==0)
      {
         flag=0;
         break;
      }
   return(flag);
}
