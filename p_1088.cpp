#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[110][110],f[110][110];
int main()
{
   int calc(int,int);
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
         scanf("%d",&a[i][j]);
   for (int i=1;i<=n;i++)
      a[i][0]=a[i][m+1]=-1;
   for (int i=1;i<=m;i++)
      a[0][i]=a[n+1][i]=-1;
   memset(f,-1,sizeof(f));
   int ans=0;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
         if (calc(i,j)>ans)
            ans=calc(i,j);
   printf("%d\n",ans);
   system("pause");
   return(0);
}
int calc(int x,int y)
{
   if (f[x][y]!=-1)
      return(f[x][y]);
   const int c[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
   f[x][y]=1;
   for (int i=0;i<4;i++)
   {
      int p=x+c[i][0],q=y+c[i][1];
      if (a[x][y]<a[p][q] && calc(p,q)+1>f[x][y])
         f[x][y]=calc(p,q)+1;
   }
   return(f[x][y]);
}
