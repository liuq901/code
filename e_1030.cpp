#include <cstdio>
#include <cstdlib>
int main()
{
   int a[51];
   a[1]=a[2]=a[3]=1;
   for (int i=4;i<=50;i++)
      a[i]=a[i-1]+a[i-3];
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      printf("%d\n",a[n]);
   }
   system("pause");
   return(0);
}
