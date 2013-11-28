#include <cstdio>
#include <cstdlib>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool map[501][501],f[501][501];
int q[250001];
int main()
{
   int n,m,l=1,r=0;
   scanf("%d%d%*c",&n,&m);
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=m;j++)
      {
         char ch;
         scanf("%c",&ch);
         map[i][j]=ch=='0';
         if (map[i][j] && (i==1 || i==n || j==1 || j==m))
         {
            q[++r]=i*10000+j;
            f[i][j]=true;
         }
      }
      scanf("%*c");
   }
   while (l<=r)
   {
      int x0=q[l]/10000,y0=q[l]%10000;
      for (int i=0;i<4;i++)
      {
         int x=x0+c[i][0],y=y0+c[i][1];
         if (!x || !y || x>n || y>m || f[x][y] || !map[x][y])
            continue;
         f[x][y]=true;
         q[++r]=x*10000+y;
      }
      l++;
   }
   int ans=0;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
         if (map[i][j] && !f[i][j])
            ans++;
   printf("%d\n",ans);
   system("pause");
   return(0);
}
