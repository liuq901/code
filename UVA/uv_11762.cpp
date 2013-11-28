#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[1000010],c[1000010];
bool vis[1000010];
int main()
{
   void init();
   double solve(int);
   init();
   int T;
   scanf("%d",&T);
   memset(vis,0,sizeof(vis));
   while (T--)
   {
      int n;
      scanf("%d",&n);
      static int id=0;
      printf("Case %d: %.10f\n",++id,solve(n));
   }
   system("pause");
   return(0);
}
bool f[1000010];
void init()
{
   f[1]=true;
   for (int i=2;i<=1000;i++)
   {
      if (f[i])
         continue;
      for (int j=i;i*j<=1000000;j++)
         f[i*j]=true;
   }
   for (int i=2;i<=1000000;i++)
      if (!f[i])
         a[++a[0]]=i;
   c[1]=0;
   for (int i=2;i<=1000000;i++)
      c[i]=c[i-1]+1-f[i];
}
double ans[1000010];
double solve(int x)
{
   if (vis[x])
      return(ans[x]);
   vis[x]=true;
   double &ret=ans[x];
   if (x==1)
      ret=0;
   else
   {
      int t;
      t=0;
      ret=0;
      for (int i=1;i<=c[x];i++)
      {
         if (x%a[i])
            continue;
         t++;
         ret+=solve(x/a[i])+1;
      }
      ret=double(c[x])/t-1+ret/t;
   }
   return(ret);
}
