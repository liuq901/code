#include <cstdio>
#include <cstdlib>
#include <cstring>
int b[201],x[401],y[401],a[401][201];
bool f[201];
int main()
{
   bool hungary(int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,m,s,c;
      scanf("%d%d%d%d",&n,&m,&s,&c);
      for (int i=1;i<=n;i++)
         scanf("%d%d",&x[i],&y[i]);
      for (int i=1;i<=n;i++)
         a[i][0]=0;
      for (int i=1;i<=m;i++)
      {
         int x0,y0;
         scanf("%d%d",&x0,&y0);
         for (int j=1;j<=n;j++)
         {
            int dist=abs(x0-x[j])+abs(y0-y[j]);
            if (dist<=s*c/200)
               a[j][++a[j][0]]=i;
         }
      }
      int ans=0;
      memset(b,0,sizeof(b));
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
