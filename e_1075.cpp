#include <cstdio>
#include <cstdlib>
int f[1010];
int main()
{
   f[0]=1;
   for (int i=1;i<=1000;i++)
      f[i]=f[i-1]+(i*(i-1)>>1)+1;
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      printf("%d\n",f[n]);
   }
   system("pause");
   return(0);
}
