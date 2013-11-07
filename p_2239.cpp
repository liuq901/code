#include <cstdio>
#include <cstdlib>
#include <cstring>
int b[301],link[301],a[30000][2];
bool f[100];
int main()
{
   bool hungary(int);
   int n;
   while (scanf("%d",&n)!=EOF)
   {
      memset(b,0,sizeof(b));
      int tot=0;
      for (int i=1;i<=n;i++)
      {
         int m;
         scanf("%d",&m);
         for (int j=1;j<=m;j++)
         {
            int x,y;
            scanf("%d%d",&x,&y);
            a[++tot][0]=(x-1)*12+y,a[tot][1]=b[i],b[i]=tot;
         }
      }
      int ans=0;
      memset(link,0,sizeof(link));
      for (int i=1;i<=n;i++)
      {
         memset(f,0,sizeof(f));
         if (hungary(i))
            ans++;
      }
      printf("%d\n",ans);
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
