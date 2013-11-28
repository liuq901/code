#include <cstdio>
#include <cstdlib>
int f[11];
int main()
{
   void init();
   init();
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (n==-1)
         break;
      printf("%d\n",f[n]);
   }
   system("pause");
   return(0);
}
void init()
{
   int c[11][11];
   for (int i=1;i<=10;i++)
   {
      c[i][0]=c[i][i]=1;
      for (int j=1;j<i;j++)
         c[i][j]=c[i-1][j-1]+c[i-1][j];
   }
   f[0]=f[1]=1;
   for (int i=2;i<=10;i++)
      for (int j=1;j<=i;j++)
         f[i]+=c[i][j]*f[i-j];
}
