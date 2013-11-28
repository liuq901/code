#include <cstdio>
#include <cstdlib>
int main()
{
   int i,t;
   int a[10];
   scanf("%d",&t);
   for (i=1;i<=t;i++)
   {
      scanf("%d%d%d%d",&a[1],&a[2],&a[3],&a[4]);
      if (a[2]-a[1]==a[3]-a[2] && a[4]-a[3]==a[3]-a[2])
         printf("%d %d %d %d %d\n",a[1],a[2],a[3],a[4],2*a[4]-a[3]);
      else
         printf("%d %d %d %d %d\n",a[1],a[2],a[3],a[4],a[4]*a[4]/a[3]);
   }
   system("pause");
   return(0);
}
