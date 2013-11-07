#include <cstdio>
#include <cstdlib>
#include <cstring>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool a[110][110],vis[110][110];
int d[110][110],q[10010][2];
int main()
{
   int op;
   while (scanf("%d",&op)==1)
   {
      op--;
      int n,m;
      scanf("%d%d",&n,&m);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
      memset(d,0,sizeof(d));
      memset(vis,0,sizeof(vis));
      int l,r;
      l=r=1;
      for (int i=1;i<=m;i++)
         if (a[1][i])
         {
            q[1][0]=1,q[1][1]=i;
            vis[1][i]=true;
            d[1][i]=1;
         }
      while (l<=r)
      {
         int x0=q[l][0],y0=q[l++][1];
         for (int i=op;i<4;i++)
         {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (!x || x>n || !y || y>m || !a[x][y] || vis[x][y])
               continue;
            vis[x][y]=true;
            d[x][y]=d[x0][y0]+1;
            q[++r][0]=x,q[r][1]=y;
         }
      }
      static int id=0;
      printf("Case %d:\n",++id);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            printf("%d%c",d[i][j],j==m?'\n':' ');
   }
   system("pause");
   return(0);
}
