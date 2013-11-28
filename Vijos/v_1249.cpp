#include <cstdio>
#include <cstdlib>
int main()
{
   int i,x,y;
   int a[10];
   for (i=1;i<=10;i++)
   {
      scanf("%d%d",&x,&y);
      if (x>y)
         if (x%4==0)
            a[i]=2;
         else
            a[i]=1;
      else
         if (y%4==0)
            a[i]=1;
         else
            a[i]=2;
   }
   for (i=1;i<=10;i++)
      printf("%d\n",a[i]);
   system("pause");
   return(0);
}
