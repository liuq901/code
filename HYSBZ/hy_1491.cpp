#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[101][101];
long long s[101][101];
int main()
{
   memset(a,26,sizeof(a));
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=m;i++)
   {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      a[x][y]=a[y][x]=z;
   }
   for (int i=1;i<=n;i++)
      a[i][i]=0;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
         s[i][j]=1;
   for (int k=1;k<=n;k++)
      for (int i=1;i<=n;i++)
      {
         if (k==i)
            continue;
         for (int j=1;j<=n;j++)
         {
            if (i==j || j==k)
               continue;
            if (a[i][k]+a[k][j]<a[i][j])
            {
               a[i][j]=a[i][k]+a[k][j];
               s[i][j]=s[i][k]*s[k][j];
            }
            else if (a[i][k]+a[k][j]==a[i][j])
               s[i][j]+=s[i][k]*s[k][j];
         }
      }
   double ans[101]={0};
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
         if (i==j)
            continue;
         for (int k=1;k<=n;k++)
         {
            if (i==k || j==k)
               continue;
            if (a[i][k]+a[k][j]==a[i][j])
               ans[k]+=s[i][k]*s[k][j]/double(s[i][j]);
         }
      }
   for (int i=1;i<=n;i++)
      printf("%.3lf\n",ans[i]);
   system("pause");
   return(0);
}
