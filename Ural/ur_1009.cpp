#include <cstdio>
#include <cstdlib>
int main()
{
   int n,k,i;
   int f[20];
   scanf("%d",&n);
   scanf("%d",&k);
   k--;
   f[0]=1;
   f[1]=k;
   for (i=2;i<=n;i++)
      f[i]=k*(f[i-1]+f[i-2]);
   printf("%d\n",f[n]);
   system("pause");
   return(0);
}
