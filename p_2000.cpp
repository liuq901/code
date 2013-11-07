#include <cstdio>
#include <cstdlib>
int main()
{
   while (1)
   {
      int x;
      scanf("%d",&x);
      if (!x)
         break;
      int s=0,n=1;
      while (s<x)
      {
         s+=n;
         n++;
      }
      n--;
      printf("%d %d\n",x,n*(n-1)*(2*n-1)/6+(x-(s-n))*n);
   }
   system("pause");
   return(0);
}
