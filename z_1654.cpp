#include <cstdio>
#include <cstdlib>
#include <cstring>
int link[2501],b[2501],a[100001][2];
bool f[2501];
int main()
{
   bool hungary(int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,m;
      scanf("%d%d%*c",&n,&m);
      char map[51][51];
      for (int i=1;i<=n;i++)
      {
         for (int j=1;j<=m;j++)
            scanf("%c",&map[i][j]);
         scanf("%*c");
      }
      bool flag;
      int sum,tot,p[51][51],q[51][51];
      sum=tot=0;
      for (int i=1;i<=n;i++)
      {
         flag=false;
         for (int j=1;j<=m;j++)
         {
            if (map[i][j]=='o')
            {
               if (!flag)
                  sum++;
               p[i][j]=sum;
               flag=true;
            }
            if (map[i][j]=='#')
               flag=false;
         }
      }
      for (int i=1;i<=m;i++)
      {
         flag=false;
         for (int j=1;j<=n;j++)
         {
            if (map[j][i]=='o')
            {
               if (!flag)
                  tot++;
               q[j][i]=tot;
               flag=true;
            }
            if (map[j][i]=='#')
               flag=false;
         }
      }
      memset(b,0,sizeof(b));
      tot=0;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            if (map[i][j]!='o')
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
      static int id=0;
      printf("Case :%d\n%d\n",++id,ans);
   }
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
