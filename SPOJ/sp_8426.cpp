#include <cstdio>
#include <cstdlib>
using namespace std;
double f[310][310];
int main()
{
   void init();
   init();
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      printf("%.2f\n",f[x][y]);
   }
   system("pause");
   return(0);
}
double p[310][310];
void init()
{
   int n=300;
   p[0][0]=1;
   for (int i=1;i<=n;i++)
   {
      p[i][0]=p[i-1][0]*0.5;
      for (int j=1;j<=n;j++)
         p[i][j]=(p[i-1][j-1]+p[i-1][j])*0.5;
   }
   for (int i=1;i<=n;i++)
      f[i][0]=1;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
         for (int k=0;k<=i;k++)
            f[i][j]+=p[i][k]*(f[k][j-1]+f[i-k][j-1]);
         f[i][j]++;
      }
}
