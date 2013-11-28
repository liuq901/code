#include <cstdio>
#include <cstdlib>
#include <cstring>
int b[1001],a[1001][1001];
bool f[1001];
int main()
{
   bool hungary(int);
   int n,m,k;
   scanf("%d%d%d",&n,&m,&k);
   for (int i=1;i<=k;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      a[x][++a[x][0]]=y;
   }
   int ans=n+m;
   for (int i=1;i<=n;i++)
   {
      memset(f,0,sizeof(f));
      if (hungary(i))
         ans--;
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
      int y=a[x][i];
      if (f[y])
         continue;
      f[y]=true;
      if (hungary(b[y]))
      {
         b[y]=x;
         return(true);
      }
   }
   return(false);
}
