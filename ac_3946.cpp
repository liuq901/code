#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=1<<30;
int a[30][30],s[30][30],f[30][30][30][30];
int main()
{
   int solve(int,int,int,int);
   int n,m,k;
   while (scanf("%d%d%d",&n,&m,&k)==3)
   {
      memset(a,0,sizeof(a));
      while (k--)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         a[x][y]=1;
      }
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
      memset(f,-1,sizeof(f));
      static int id=0;
      printf("Case %d: %d\n",++id,solve(1,1,n,m));
   }
   system("pause");
   return(0);
}
int solve(int x1,int y1,int x2,int y2)
{
   int calc(int,int,int,int);
   if (f[x1][y1][x2][y2]!=-1)
      return(f[x1][y1][x2][y2]);
   if (calc(x1,y1,x2,y2)==1)
      return(f[x1][y1][x2][y2]=0);
   int ret=inf;
   for (int i=x1;i<x2;i++)
   {
      if (!calc(x1,y1,i,y2) || !calc(i+1,y1,x2,y2))
         continue;
      ret=min(ret,solve(x1,y1,i,y2)+solve(i+1,y1,x2,y2)+y2-y1+1);
   }
   for (int i=y1;i<y2;i++)
   {
      if (!calc(x1,y1,x2,i) || !calc(x1,i+1,x2,y2))
         continue;
      ret=min(ret,solve(x1,y1,x2,i)+solve(x1,i+1,x2,y2)+x2-x1+1);
   }
   return(f[x1][y1][x2][y2]=ret);
}
int calc(int x1,int y1,int x2,int y2)
{
   return(s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]);
}
