#include <cstdio>
#include <cstdlib>
int main()
{
   int f(int,int);
   int x0,y0,p,sum;
   scanf("%d%d",&x0,&y0);
   sum=0;
   for (p=x0;p<=y0;p++)
      if (y0%p==0 && f(p,y0/p*x0)==x0)
         sum++;
   printf("%d\n",sum);
   system("pause");
   return(0);
}
int f(int x,int y)
{
   if (x==0)
      return(y);
   else
      return(f(y%x,x));
}
