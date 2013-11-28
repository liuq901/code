#include <cstdio>
#include <cstdlib>
int main()
{
   int i,n,x,max;
   max=0;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%d",&x);
      if (x>max)
         max=x;
   }
   printf("%d\n",max);
   system("pause");
   return(0);
}
