#include <cstdio>
#include <cstdlib>
#include <cstring>
int tot,max,b[310],a[40001][4];
int main()
{
   void add(int,int,int);
   bool build();
   int dinic(int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,m,sum=0;
      scanf("%d%d",&n,&m);
      memset(b,0,sizeof(b));
      max=tot=0;
      for (int i=1;i<=n;i++)
      {
         int p,r,d;
         scanf("%d%d%d",&p,&r,&d);
         if (d>max)
            max=d;
         for (int j=r;j<=d;j++)
            add(i,j+n,1);
         sum+=p;
         add(0,i,p);
      }
      max+=n+1;
      for (int i=n+1;i<max;i++)
         add(i,max,m);
      if (sum>m*(max-n-1))
      {
         printf("Boss xnby is angry!\n");
         continue;
      }
      int ans=0;
      while (build())
         ans+=dinic(0,1<<30);
      printf("%s\n",ans!=sum?"Boss xnby is angry!":"Boss xnby is happy!");
   }
   system("pause");
   return(0);
}
void add(int x,int y,int z)
{
   a[++tot][0]=y,a[tot][1]=z,a[tot][2]=tot+1,a[tot][3]=b[x];
   b[x]=tot;
   a[++tot][0]=x,a[tot][1]=0,a[tot][2]=tot-1,a[tot][3]=b[y];
   b[y]=tot;
}
int d[310];
bool build()
{
   memset(d,0,sizeof(d));
   int l,r,q[310];
   l=r=1;
   d[0]=1,q[1]=0;
   while (l<=r)
   {
      int x=q[l];
      for (int i=b[x];i;i=a[i][3])
      {
         int y=a[i][0];
         if (d[y] || !a[i][1])
            continue;
         d[y]=d[x]+1;
         q[++r]=y;
         if (y==max)
            return(true);
      }
      l++;
   }
   return(false);
}
int dinic(int x,int flow)
{
   int min(int,int);
   if (x==max)
      return(flow);
   int p=flow;
   for (int i=b[x];i;i=a[i][3])
   {
      int y=a[i][0];
      if (d[y]!=d[x]+1 || !a[i][1])
         continue;
      int k=dinic(y,min(p,a[i][1]));
      a[i][1]-=k;
      a[a[i][2]][1]+=k;
      p-=k;
      if (!p)
         return(flow);
   }
   if (p==flow)
      d[x]=-1;
   return(flow-p);
}
int min(int x,int y)
{
   return(x<y?x:y);
}
