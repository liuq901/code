#include <cstdio>
#include <cstdlib>
int main()
{
   int s=0,i,x,a[10];
   for (i=0;i<10;i++)
   {
      scanf("%d",&a[i]);
      a[i]-=30;
   }
   scanf("%d",&x);
   for (i=0;i<10;i++)
      if (a[i]<=x)
         s+=1;
   printf("%d\n",s);
   system("pause");
   return(0);
}
