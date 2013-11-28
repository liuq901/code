#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=1<<30;
int S,T,ans[100][100],a[200][200];
int main()
{
   bool build();
   int dinic(int,int);
   while (1)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      S=0,T=n+m+1;
      int s1,s2;
      s1=s2=0;
      memset(a,0,sizeof(a));
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         a[S][i]=x;
         s1+=x;
      }
      for (int i=1;i<=m;i++)
      {
         int x;
         scanf("%d",&x);
         a[i+n][T]=x;
         s2+=x;
      }
      static bool first=true;
      if (!first)
         printf("\n");
      first=false;
      if (s1!=s2)
      {
         printf("Impossible\n");
         continue;
      }
      memset(ans,-1,sizeof(ans));
      int flow=0;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            a[i][j+n]=1;
      while (build())
         flow+=dinic(S,inf);
      if (flow!=s1)
         printf("Impossible\n");
      else
      {
         for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
               ans[i][j]=false;
               if (a[i][j+n])
               {
                  a[i][j+n]=0;
                  continue;
               }
               a[j+n][i]=0;
               a[S][i]++,a[i][S]--;
               a[T][j+n]--,a[j+n][T]++;
               if (!build())
               {
                  ans[i][j]=true;
                  a[i][j+n]=1;
               }
               build(),dinic(S,inf);
            }
         for (int i=1;i<=n;i++)
         {
            for (int j=1;j<=m;j++)
               printf("%c",ans[i][j]?'Y':'N');
            printf("\n");
         }
      }
   }
   system("pause");
   return(0);
}
int d[200],q[200];
bool build()
{
   memset(d,0,sizeof(d));
   int l,r;
   l=r=1,d[S]=1,q[1]=S;
   while (l<=r)
   {
      int x=q[l++];
      for (int i=0;i<=T;i++)
      {
         if (d[i] || !a[x][i])
            continue;
         d[i]=d[x]+1;
         q[++r]=i;
         if (i==T)
            return(true);
      }
   }
   return(false);
}
int dinic(int x,int flow)
{
   if (x==T)
      return(flow);
   int k=flow;
   for (int i=0;i<=T;i++)
   {
      if (d[i]!=d[x]+1 || !a[x][i])
         continue;
      int t=dinic(i,min(k,a[x][i]));
      k-=t;
      a[x][i]-=t;
      a[i][x]+=t;
      if (!k)
         return(flow);
   }
   if (k==flow)
      d[x]=-1;
   return(flow-k);
}
