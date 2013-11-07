#include <cstdio>
#include <cstdlib>
int main()
{
   int gcd(int,int);
   int a,b,t,x,s,flag;
   scanf("%d%d",&a,&b);
   x=gcd(a,b);
   t=a/x+b/x;
   s=0;
   flag=1;
   while (1)
   {
      if (t==1)
         break;
      if (t%2==1)
      {
         flag=0;
         break;
      }
      s++;
      t/=2;
   }
   if (!flag)
      printf("-1\n");
   else
      printf("%d\n",s);
   system("pause");
   return(0);
}
int gcd(int a,int b)
{
   if (b==0)
      return(a);
   else
      return(gcd(b,a%b));
}
