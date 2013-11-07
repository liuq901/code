#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;
int a[30][30];
int s[10010];
int main()
{
   int km();
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,k,m;
      scanf("%d%d%d%*c",&n,&k,&m);
      for (int i=1;i<=n;i++)
      {
         char ch=' ';
         while (!isalpha(ch))
            scanf("%c",&ch);
         s[i]=ch-'A'+1;
      }
      for (int i=1;i<=m;i++)
      {
         memset(a,0,sizeof(a));
         for (int j=1;j<=n;j++)
         {
            char ch=' ';
            while (!isalpha(ch))
               scanf("%c",&ch);
            a[s[j]][ch-'A'+1]++;
         }
         int ans=km();
         printf("%.4f\n",double(ans)/n);
      }
   }
   system("pause");
   return(0);
}
int n,b[30],dx[30],dy[30],slack[30];
bool f[30],g[30];
int km()
{
   bool hungary(int);
   memset(b,0,sizeof(b));
   memset(dx,0,sizeof(dx));
   memset(dy,0,sizeof(dy));
   n=26;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
         dx[i]=max(dx[i],a[i][j]);
   for (int i=1;i<=n;i++)
   {
      memset(slack,63,sizeof(slack));
      memset(f,0,sizeof(f));
      memset(g,0,sizeof(g));
      while (!hungary(i))
      {
         int d=1<<30;
         for (int i=1;i<=n;i++)
            if (!g[i] && slack[i]<d)
               d=slack[i];
         for (int i=1;i<=n;i++)
         {
            if (f[i])
               dx[i]-=d;
            if (g[i])
               dy[i]+=d;
         }
         memset(f,0,sizeof(f));
         memset(g,0,sizeof(g));
      }
   }
   int ans=0;
   for (int i=1;i<=n;i++)
      ans+=a[b[i]][i];
   return(ans);
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
