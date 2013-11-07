#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   char a[2000][75],*p;
   int b[2000];
   int n,i,j,max;
   scanf("%d",&n);
   for (i=0;i<n;i++)
      scanf("%s",a[i]);
   for (i=0;i<n;i++)
   {
      b[i]=1;
      for (j=0;j<=i-1;j++)
      {
         p=strstr(a[i],a[j]);
         if (b[j]+1>b[i] && p==a[i])
            b[i]=b[j]+1;
      }
   }
   max=0;
   for (i=0;i<n;i++)
   {
      if (b[i]>max)
         max=b[i];
   }
   printf("%d\n",max);
   system("pause");
   return(0);
}
