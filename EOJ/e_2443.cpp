#include <cstdio>
#include <cstdlib>
int main()
{
   int calc(int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      printf("%d\n",calc(n));
   }
   system("pause");
   return(0);
}
int calc(int x)
{
   if (x<10)
      return(x);
   int s=0;
   while (x)
   {
      s+=x%10;
      x/=10;
   }
   return(calc(s));
}
