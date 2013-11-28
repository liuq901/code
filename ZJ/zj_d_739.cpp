#include <cstdio>
#include <cstdlib>
#include <cstring>
int b[110],link[110],a[100000][2];
bool f[110];
int main()
{
   bool hungary(int);
   while (1)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      memset(b,0,sizeof(b));
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         a[i][0]=y,a[i][1]=b[x],b[x]=i;
      }
      memset(link,0,sizeof(link));
      int ans=n;
      for (int i=1;i<=n;i++)
      {
         memset(f,0,sizeof(f));
         ans-=hungary(i);
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
