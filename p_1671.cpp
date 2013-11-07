#include <cstdio>
#include <cstdlib>
double ans[1010];
int main()
{
   void init();
   init();
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      printf("%d %.0f\n",n,ans[n]);
   }
   system("pause");
   return(0);
}
double f[1010][1010];
void init()
{
   f[1][1]=ans[1]=1;
   for (int i=2;i<=1000;i++)
      for (int j=1;j<=i;j++)
      {
         f[i][j]=f[i-1][j]*j+f[i-1][j-1];
         ans[i]+=f[i][j];
      }
}
