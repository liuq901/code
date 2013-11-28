#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf=1<<30;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int S,T,tot,b[5010],a[1000000][3],A[60][60],B[60][60],C[60][60];
int main()
{
   void add(int,int,int);
   bool build();
   int dinic(int,int);
   int test;
   scanf("%d",&test);
   while (test--)
   {
      int n,m,g,s;
      scanf("%d%d%d%d",&n,&m,&g,&s);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            scanf("%d",&A[i][j]);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            scanf("%d",&B[i][j]);
      int t=0;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            C[i][j]=++t;
      S=0,T=2*t+1,tot=1;
      memset(b,0,sizeof(b));
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            if (i+j&1)
            {
               add(S,C[i][j],A[i][j]);
               add(C[i][j]+t,T,B[i][j]);
               for (int k=0;k<4;k++)
               {
                  int x=i+c[k][0],y=j+c[k][1];
                  if (!x || x>n || !y || y>m)
                     continue;
                  add(C[i][j]+t,C[x][y],g);
               }
            }
            else
            {
               add(S,C[i][j],B[i][j]);
               add(C[i][j]+t,T,A[i][j]);
               for (int k=0;k<4;k++)
               {
                  int x=i+c[k][0],y=j+c[k][1];
                  if (!x || x>n || !y || y>m)
                     continue;
                  add(C[i][j]+t,C[x][y],s);
               }
            }
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            add(C[i][j],C[i][j]+t,A[i][j]+B[i][j]);
      long long ans=0;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            ans+=A[i][j]+B[i][j];
      while (build())
         ans-=dinic(S,inf);
      static int id=0;
      printf("Case %d: ",++id);
      cout<<ans<<endl;
   }
   system("pause");
   return(0);
}
void add(int x,int y,int c)
{
   a[++tot][0]=y,a[tot][1]=c,a[tot][2]=b[x],b[x]=tot;
   a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int d[5010],q[5010];
bool build()
{
   memset(d,0,sizeof(d));
   int l,r;
   d[S]=1,q[l=r=1]=S;
   while (l<=r)
   {
      int x=q[l++];
      for (int i=b[x];i;i=a[i][2])
      {
         int y=a[i][0];
         if (d[y] || !a[i][1])
            continue;
         d[y]=d[x]+1;
         q[++r]=y;
         if (y==T)
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
   for (int i=b[x];i;i=a[i][2])
   {
      int y=a[i][0];
      if (d[y]!=d[x]+1 || !a[i][1])
         continue;
      int t=dinic(y,min(k,a[i][1]));
      a[i][1]-=t;
      a[i^1][1]+=t;
      k-=t;
      if (!k)
         return(flow);
   }
   if (k==flow)
      d[x]=-1;
   return(flow-k);
}
