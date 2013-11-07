#include <cstdio>
#include <cstdlib>
#include <cstring>
int b[2501],a[2501][51];
bool f[2501];
int main()
{
   bool hungary(int);
   int n,m;
   scanf("%d%d%*c",&n,&m);
   bool map[51][51];
   memset(map,0,sizeof(map));
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=m;j++)
      {
         char ch;
         scanf("%c",&ch);
         map[i][j]=ch=='*';
      }
      scanf("%*c");
   }
   int s=0,t=0,p[51][51],q[51][51];
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
      {
         if (!map[i][j])
            continue;
         if (map[i][j-1])
            p[i][j]=p[i][j-1];
         else
            p[i][j]=++s;
      }
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
      {
         if (!map[i][j])
            continue;
         if (map[i-1][j])
            q[i][j]=q[i-1][j];
         else
            q[i][j]=++t;
      }
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
      {
         if (!map[i][j])
            continue;
         int x=p[i][j],y=q[i][j];
         a[x][++a[x][0]]=y;
      }
   int ans=0;
   for (int i=1;i<=s;i++)
   {
      memset(f,0,sizeof(f));
      if (hungary(i))
         ans++;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
bool hungary(int x)
{
   if (!x)
      return(true);
   for (int i=1;i<=a[x][0];i++)
   {
      int t=a[x][i];
      if (f[t])
         continue;
      f[t]=true;
      if (hungary(b[t]))
      {
         b[t]=x;
         return(true);
      }
   }
   return(false);
}
