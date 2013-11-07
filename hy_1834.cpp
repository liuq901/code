#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,k,b[1001],a[20001][5];
int main()
{
   void add(int,int,int,int,int);
   bool build();
   int dinic(int,int),spfa();
   int m;
   scanf("%d%d%d",&n,&m,&k);
   for (int i=1;i<=m;i++)
   {
      int x,y,w,c;
      scanf("%d%d%d%d",&x,&y,&w,&c);
      add(i,x,y,w,0);
      add(i+m,x,y,1<<30,c);
   }
   int ans=0,cost=0;
   while (build())
      ans+=dinic(1,1<<30);
   while (k)
      cost+=spfa();
   printf("%d %d\n",ans,cost);
   system("pause");
   return(0);
}
void add(int num,int x,int y,int c,int cost)
{
   a[num][0]=y;
   a[num][1]=c;
   a[num][2]=cost;
   a[num][3]=num+10000;
   a[num][4]=b[x];
   b[x]=num;
   a[num+10000][0]=x;
   a[num+10000][1]=0;
   a[num+10000][2]=-cost;
   a[num+10000][3]=num;
   a[num+10000][4]=b[y];
   b[y]=num+10000;
}
int d[1001];
bool build()
{
   memset(d,0,sizeof(d));
   int q[1001],l,r;
   l=r=q[1]=d[1]=1;
   while (l<=r)
   {
      int x=q[l];
      for (int i=b[x];i;i=a[i][4])
      {
         int y=a[i][0];
         if (d[y] || !a[i][1] || a[i][2])
            continue;
         d[y]=d[x]+1;
         q[++r]=y;
         if (y==n)
            return(true);
      }
      l++;
   }
   return(false);
}
int dinic(int x,int flow)
{
   int min(int,int);
   if (x==n)
      return(flow);
   int k=flow;
   for (int i=b[x];i;i=a[i][4])
   {
      int y=a[i][0];
      if (d[y]!=d[x]+1 || !a[i][1] || a[i][2])
         continue;
      int t=dinic(y,min(k,a[i][1]));
      a[i][1]-=t;
      a[a[i][3]][1]+=t;
      k-=t;
      if (!k)
         return(flow);
   }
   if (k==flow)
      d[x]=-1;
   return(flow-k);
}
int pre[1001],p[1001];
int spfa()
{
   int min(int,int);
   memset(d,26,sizeof(d));
   bool f[1001]={0};
   int q[1001],l,r;
   f[1]=true;
   r=q[1]=1;
   l=d[1]=0;
   while (l!=r)
   {
      l=l==n?1:l+1;
      int x=q[l];
      for (int i=b[x];i;i=a[i][4])
      {
         if (!a[i][1])
            continue;
         int y=a[i][0];
         if (d[x]+a[i][2]<d[y])
         {
            d[y]=d[x]+a[i][2];
            pre[y]=x;
            p[y]=i;
            if (!f[y])
            {
               f[y]=true;
               r=r==n?1:r+1;
               q[r]=y;
            }
         }
      }
      f[x]=false;
   }
   int x=n,flow=1<<30;
   while (x!=1)
   {
      flow=min(flow,a[p[x]][1]);
      x=pre[x];
   }
   if (flow>=k)
   {
      flow=k;
      k=0;
      return(d[n]*flow);
   }
   else
   {
      x=n;
      while (x!=1)
      {
         int y=p[x];
         a[y][1]-=flow;
         a[a[y][3]][1]+=flow;
         x=pre[x];
      }
      k-=flow;
      return(d[n]*flow);
   }
}
int min(int x,int y)
{
   return(x<y?x:y);
}
