#include <cstdio>
#include <cstdlib>
#include <cstring>
const int inf=(1<<30)-1;
int tot=1,end,b[610],v[610],c[610],a[1000000][3];
bool flag[610];
int main()
{
   void add(int,int,int),topsort();
   bool build();
   int dinic(int,int);
   int n,m;
   scanf("%d%d",&n,&m);
   end=n*m+1;
   for (int i=1;i<=n*m;i++)
   {
      int p;
      scanf("%d%d",&v[i],&p);
      for (int j=1;j<=p;j++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         add(x*m+y+1,i,inf);
         c[x*m+y+1]++;
      }
      if (i%m!=1)
      {
         add(i-1,i,inf);
         c[i-1]++;
      }
   }
   topsort();
   int ans=0;
   for (int i=1;i<end;i++)
   {
      if (!flag[i])
         continue;
      if (v[i]>0)
      {
         ans+=v[i];
         add(0,i,v[i]);
      }
      else
         add(i,end,-v[i]);
   }
   while (build())
      ans-=dinic(0,inf);
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void add(int x,int y,int c)
{
   a[++tot][0]=y,a[tot][1]=c,a[tot][2]=b[x],b[x]=tot;
   a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
void topsort()
{
   int l,r,q[610];
   l=1,r=0;
   for (int i=1;i<end;i++)
      if (!c[i])
         q[++r]=i;
   while (l<=r)
   {
      int x=q[l];
      flag[x]=true;
      for (int i=b[x];i;i=a[i][2])
      {
         int y=a[i][0];
         if (i&1)
         {
            c[y]--;
            if (!c[y])
               q[++r]=y;
         }
      }
      l++;
   }
}
int d[610];
bool build()
{
   int l,r,q[610];
   memset(d,0,sizeof(d));
   l=r=1;
   q[1]=0;
   d[0]=1;
   while (l<=r)
   {
      int x=q[l];
      for (int i=b[x];i;i=a[i][2])
      {
         int y=a[i][0];
         if (d[y] || !a[i][1])
            continue;
         d[y]=d[x]+1;
         q[++r]=y;
         if (y==end)
            return(true);
      }
      l++;
   }
   return(false);
}
int dinic(int x,int flow)
{
   int min(int,int);
   if (x==end)
      return(flow);
   int k=flow;
   for (int i=b[x];i;i=a[i][2])
   {
      int y=a[i][0];
      if (d[y]!=d[x]+1 || !a[i][1])
         continue;
      int t=dinic(y,min(k,a[i][1]));
      k-=t;
      a[i][1]-=t;
      a[i^1][1]+=t;
      if (!k)
         return(flow);
   }
   if (k==flow)
      d[x]=-1;
   return(flow-k);
}
int min(int x,int y)
{
   return(x<y?x:y);
}
