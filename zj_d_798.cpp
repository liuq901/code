#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int f[10][10][510][510];
int main()
{
   int log(int);
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
         scanf("%d",&f[0][0][i][j]);
   for (int i=0;i<=log(n);i++)
      for (int j=0;j<=log(m);j++)
      {
         if (!i && !j)
            continue;
         for (int x=1;x<=n;x++)
         {
            if (x+(1<<i)-1>n)
               break;
            for (int y=1;y<=m;y++)
            {
               if (y+(1<<j)-1>m)
                  break;
               if (!i)
                  f[i][j][x][y]=max(f[i][j-1][x][y],f[i][j-1][x][y+(1<<j-1)]);
               else
                  f[i][j][x][y]=max(f[i-1][j][x][y],f[i-1][j][x+(1<<i-1)][y]);
            }
         }
      }
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int x1,y1,x2,y2;
      scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
      int p=log(x2-x1+1),q=log(y2-y1+1);
      printf("%d\n",max(max(f[p][q][x1][y1],f[p][q][x1][y2-(1<<q)+1]),max(f[p][q][x2-(1<<p)+1][y1],f[p][q][x2-(1<<p)+1][y2-(1<<q)+1])));
   }
   system("pause");
   return(0);
}
int log(int x)
{
   int ans=-1;
   while (x)
   {
      ans++;
      x>>=1;
   }
   return(ans);
}
