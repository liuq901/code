#include <cstdio>
#include <cstdlib>
#include <cstring>
const int inf=1<<26;
int n,b[101],dx[101],dy[101],slack[101],p[101],a[101][101];
bool f[101],g[101];
int main()
{
   bool hungary(int);
   void print(int,int);
   int m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=m;i++)
   {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      a[x][y]=inf-z;
   }
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
         if (a[i][j]>dx[i])
            dx[i]=a[i][j];
   for (int i=1;i<=n;i++)
   {
      memset(slack,26,sizeof(slack));
      memset(f,0,sizeof(f));
      memset(g,0,sizeof(g));
      while (!hungary(i))
      {
         int d=1<<30;
         for (int j=1;j<=n;j++)
            if (!g[j] && slack[j]<d)
               d=slack[j];
         for (int j=1;j<=n;j++)
         {
            if (f[j])
               dx[j]-=d;
            if (g[j])
               dy[j]+=d;
         }
         memset(f,0,sizeof(f));
         memset(g,0,sizeof(g));
      }
   }
   int ans=0,s=0;
   memset(f,0,sizeof(f));
   for (int i=1;i<=n;i++)
      if (a[b[i]][i])
      {
         ans+=inf-a[b[i]][i];
         p[i]=b[i];
         f[b[i]]=true;
      }
      else
         s++;
   printf("%d %d\n",s,ans);
   for (int i=1;i<=n;i++)
      if (!f[i])
      {
         print(i,1);
         printf("\n");
      }
   system("pause");
   return(0);
}
bool hungary(int x)
{
   if (!x)
      return(true);
   f[x]=true;
   for (int i=1;i<=n;i++)
   {
      if (g[i])
         continue;
      int t=dx[x]+dy[i]-a[x][i];
      if (!t)
      {
         g[i]=true;
         if (hungary(b[i]))
         {
            b[i]=x;
            return(true);
         }
      }
      else if (t<slack[i])
         slack[i]=t;
   }
   return(false);
}
void print(int x,int dep)
{
   if (!p[x])
      printf("%d",dep);
   else
      print(p[x],dep+1);
   printf(" %d",x);
}
