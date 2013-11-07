#include <cstdio>
#include <cstdlib>
#include <cstring>
char f[1000001];
int main()
{
   int n,i,j,s;
   scanf("%d",&n);
   memset(f,0,sizeof(f));
   f[1]=1;
   for (i=2;i<=n;i++)
   {
      if (f[i])
         continue;
      j=1;
      while (1)
      {
         j++;
         if (i*j>n)
            break;
         f[i*j]=1;
      }
   }
   s=0;
   for (i=3;i<=n-2;i++)
      if (!f[i] && !f[i+2])
         s++;
   printf("%d\n",s);
   for (i=3;i<=n-2;i++)
      if (!f[i] && !f[i+2])
         printf("2 %d\n",i);
   system("pause");
   return(0);
}
