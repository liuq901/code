#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
int main()
{
   int i,j,n;
   int a[300],f[60001];
   scanf("%d",&n);
   for (i=0;i<=sqrt(n)+1;i++)
      a[i]=i*i;
   memset(f,26,sizeof(f));
   f[0]=0;
   for (i=1;i<=n;i++)
   {
      j=-1;
      while (1)
      {
         j++;
         if (i-a[j]<0)
            break;
         if (f[i-a[j]]+1<f[i])
            f[i]=f[i-a[j]]+1;
      }
   }
   printf("%d\n",f[n]);
   system("pause");
   return(0);
}
