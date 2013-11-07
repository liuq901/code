#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
double c[201][201],f[101][101],g[101][101][101];
struct LastMarble
{
   double winningChance(int r,int b,int removed)
   {
      for (int i=1;i<=r;i++)
         for (int j=0;j<=b;j++)
            g[i][j][0]=1;
      for (int k=1;k<=removed;k++)
         for (int i=1;i<=r;i++)
         {
            g[i][0][k]=g[i-1][0][k-1];
            for (int j=1;j<=b;j++)
               g[i][j][k]=g[i-1][j][k-1]*i/(i+j)+g[i][j-1][k-1]*j/(i+j);
         }
      for (int i=0;i<=r;i++)
         for (int j=0;j<=b;j++)
         {
            if (i+j<=removed)
               continue;
            for (int m=1;m<=min(i+j,3);m++)
            {
               double sum=0;
               for (int p=0;p<=m;p++)
               {
                  int q=m-p;
                  if (p>i || q>j)
                     continue;
                  double tmp=g[i-p][j-q][removed]/g[i][j][removed];
                  tmp*=calc(p,i)*calc(q,j)/calc(m,i+j);
                  tmp*=1-f[i-p][j-q];
                  sum+=tmp;
               }
               if (sum>f[i][j])
                  f[i][j]=sum;
            }
         }
      return(f[r][b]);
   }
   double calc(int x,int y)
   {
      if (c[x][y]!=0)
         return(c[x][y]);
      if (x==y || x==0)
         c[x][y]=1;
      else
         c[x][y]=calc(x-1,y-1)+calc(x,y-1);
      return(c[x][y]);
   }
};
int main()
{
   int x,y,z;
   scanf("%d%d%d",&x,&y,&z);
   LastMarble t;
   printf("%.16lf\n",t.winningChance(x,y,z));
   system("pause");
   return(0);
}
