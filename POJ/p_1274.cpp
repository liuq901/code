#include <cstdio>
#include <cstdlib>
#include <cstring>
int b[201],a[201][201];
bool f[201];
int main()
{
   bool hungary(int);
   int n,m;
   while (scanf("%d%d",&n,&m)!=EOF)
   {
      for (int i=1;i<=n;i++)
      {
         scanf("%d",&a[i][0]);
         for (int j=1;j<=a[i][0];j++)
         {
            int x;
            scanf("%d",&x);
            a[i][j]=x;
         }
      }
      memset(b,0,sizeof(b));
      int ans=0;
      for (int i=1;i<=n;i++)
      {
         memset(f,false,sizeof(f));
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
   if (x==0)
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
