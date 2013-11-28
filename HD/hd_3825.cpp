#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define SQR(x) ((x)*(x))
int x[110],y[110],t[110],p[110],f[110];
double d[110];
bool vis[110][110];
int main()
{
   bool cmp(int,int);
   double dist(int,int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,v;
      scanf("%d%d",&n,&v);
      for (int i=1;i<=n;i++)
      {
         scanf("%d%d%d",&x[i],&y[i],&t[i]);
         p[i]=i;
      }
      sort(p+1,p+n+1,cmp);
      memset(vis,0,sizeof(vis));
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            vis[i][j]=i!=j && (t[j]-t[i])*v>=dist(i,j);
      int ans=0;
      double D;
      for (int S=1;S<=n;S++)
      {
         memset(f,0,sizeof(f));
         f[S]=1;
         for (int i=1;i<=n;i++)
         {
            int x=p[i];
            for (int j=1;j<=n;j++)
               if (vis[x][j])
                  f[j]=max(f[j],f[x]+1);
         }
         for (int i=1;i<=n;i++)
            d[i]=1e100;
         d[S]=0;
         for (int i=1;i<=n;i++)
         {
            int x=p[i];
            for (int j=1;j<=n;j++)
               if (vis[x][j] && f[x]+1==f[j])
                  d[j]=min(d[j],d[x]+dist(x,j));
         }
         for (int i=1;i<=n;i++)
         {
            if (f[i]>ans)
               ans=f[i],D=1e100;
            if (f[i]==ans)
               D=min(D,d[i]+dist(S,i));
         }
      }
      static int id=0;
      printf("Case %d: %d %.3f\n",++id,ans,D);
   }
   system("pause");
   return(0);
}
bool cmp(int x,int y)
{
   return(t[x]<t[y]);
}
double dist(int i,int j)
{
   return(sqrt(double(SQR(x[i]-x[j])+SQR(y[i]-y[j]))));
}
