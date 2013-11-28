#include <cstdio>
#include <cstdlib>
int ans[90];
int main()
{
   void init();
   init();
   int n;
   while (scanf("%d",&n)==1)
      printf("%d\n",ans[n]);
   system("pause");
   return(0);
}
int f[90][90];
void init()
{
   for (int i=1;i<=80;i++)
      f[i][i]=1;
   for (int i=1;i<=80;i++)
      for (int j=1;j<=i;j++)
      {
         for (int k=j;k<=80-i;k++)
            f[i+k][k]+=f[i][j];
         ans[i]+=f[i][j];
      }
}
