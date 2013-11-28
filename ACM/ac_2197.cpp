#include <cstdio>
#include <cstdlib>
#include <cstring>
int ans,flow,S,T,tot,b[100],a[1000000][4];
int main()
{
   void add(int,int,int,int);
   bool spfa();
   int test;
   scanf("%d",&test);
   while (test--)
   {
      int n,m,K;
      scanf("%d%d%d",&n,&m,&K);
      memset(b,0,sizeof(b));
      tot=1;
      for (int i=1;i<=m;i++)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         x++,y++;
         add(x,y+n,1,z);
      }
      T=(n<<1)+1;
      for (int i=1;i<=n;i++)
      {
         add(S,i,K,0);
         add(i+n,T,K,0);
      }
      flow=ans=0;
      while (spfa());
      if (flow!=K*n)
         printf("-1\n");
      else
         printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void add(int x,int y,int c,int v)
{
   a[++tot][0]=y,a[tot][1]=c,a[tot][2]=v,a[tot][3]=b[x],b[x]=tot;
   a[++tot][0]=x,a[tot][1]=0,a[tot][2]=-v,a[tot][3]=b[y],b[y]=tot;
}
int q[100],d[100],p[100],pre[100];
bool vis[100];
bool spfa()
{
   memset(d,63,sizeof(d));
   memset(vis,0,sizeof(vis));
   int l=0,r=1,inf=d[0];
   q[1]=S,d[S]=0,vis[S]=true;
   while (l!=r)
   {
      l++;
      if (l==100)
         l=1;
      int x=q[l];
      for (int i=b[x];i;i=a[i][3])
      {
         int y=a[i][0];
         if (a[i][1] && d[x]+a[i][2]<d[y])
         {
            d[y]=d[x]+a[i][2];
            pre[y]=x;
            p[y]=i;
            if (!vis[y])
            {
               vis[y]=true;
               r++;
               if (r==100)
                  r=1;
               q[r]=y;
            }
         }
      }
      vis[x]=false;
   }
   if (d[T]==inf)
      return(false);
   for (int i=T;i!=S;i=pre[i])
   {
      int x=p[i];
      a[x][1]--,a[x^1][1]++;
   }
   flow++;
   ans+=d[T];
   return(true);
}
