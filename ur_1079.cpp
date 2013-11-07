#include <cstdio>
#include <cstdlib>
int a[100000],f[100000];
int main()
{
   int i,n;
   a[0]=f[0]=0;
   a[1]=f[1]=1;
   for (i=2;i<100000;i++)
   {
      if (i%2==0)
         a[i]=a[i/2];
      else
         a[i]=a[i/2]+a[i/2+1];
      if (f[i-1]>a[i])
         f[i]=f[i-1];
      else
         f[i]=a[i];
   }
   while (1)
   {
      scanf("%d",&n);
      if (n==0)
         break;
      printf("%d\n",f[n]);
   }
   system("pause");
   return(0);
}
