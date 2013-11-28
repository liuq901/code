#include <cstdio>
#include <cstdlib>
int main()
{
   int t;
   scanf("%d",&t);
   for (int id=1;id<=t;id++)
   {
      int n,f[50][2];
      scanf("%d",&n);
      f[1][0]=f[1][1]=1;
      for (int i=2;i<=n;i++)
      {
         f[i][0]=f[i-1][0]+f[i-1][1];
         f[i][1]=f[i-1][0];
      }
      printf("Scenario #%d:\n%d\n\n",id,f[n][0]+f[n][1]);
   }
   system("pause");
   return(0);
}
