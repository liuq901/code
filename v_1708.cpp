#include <cstdio>
#include <cstdlib>
#include <cstring>
int link[10001],b[10001],a[1000001][2];
bool f[10001];
int main()
{
   bool hungary(int);
   int t;
   int n,m;
   scanf("%d%d%*c",&n,&m);
   char map[101][101];
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=m;j++)
         scanf("%c",&map[i][j]);
      scanf("%*c");
   }
   bool flag;
   int sum,tot,p[101][101],q[101][101];
   sum=tot=0;
   for (int i=1;i<=n;i++)
   {
      flag=false;
      for (int j=1;j<=m;j++)
      {
         if (map[i][j]=='E')
         {
            if (!flag)
               sum++;
            p[i][j]=sum;
            flag=true;
         }
         if (map[i][j]=='W')
            flag=false;
      }
   }
   for (int i=1;i<=m;i++)
   {
      flag=false;
      for (int j=1;j<=n;j++)
      {
         if (map[j][i]=='E')
         {
            if (!flag)
               tot++;
            q[j][i]=tot;
            flag=true;
         }
         if (map[j][i]=='W')
            flag=false;
      }
   }
   memset(b,0,sizeof(b));
   tot=0;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
      {
         if (map[i][j]!='E')
            continue;
         int x=p[i][j],y=q[i][j];
         a[++tot][0]=y;
         a[tot][1]=b[x];
         b[x]=tot;
      }
   int ans=0;
   memset(link,0,sizeof(link));
   for (int i=1;i<=sum;i++)
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
   for (int i=b[x];i;i=a[i][1])
   {
      int y=a[i][0];
      if (f[y])
         continue;
      f[y]=true;
      if (hungary(link[y]))
      {
         link[y]=x;
         return(true);
      }
   }
   return(false);
}
