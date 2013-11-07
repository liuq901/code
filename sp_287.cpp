#include <cstdio>
#include <cstdlib>
#include <cstring>
const int inf=1<<30;
int n,m,k,p[501],e[260000][2];
int main()
{
   bool check(int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      scanf("%d%d%d",&n,&m,&k);
      for (int i=1;i<=k;i++)
         scanf("%d",&p[i]);
      for (int i=1;i<=m;i++)
         scanf("%d%d",&e[i][0],&e[i][1]);
      int l=1,r=n,ans;
      while (l<=r)
      {
         int mid=l+r>>1;
         if (check(mid))
         {
            r=mid-1;
            ans=mid;
         }
         else
            l=mid+1;
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
int b[501],a[260000][4];
bool check(int value)
{
   void add(int,int,int,int,int);
   bool build();
   int dinic(int,int);
   memset(b,0,sizeof(b));
   for (int i=1;i<=m;i++)
   {
      add(i,e[i][0],e[i][1],value,i+m);
      add(i+m,e[i][1],e[i][0],value,i);
   }
   for (int i=1;i<=k;i++)
   {
      add(2*m+i,0,p[i],1,2*m+k+i);
      add(2*m+k+i,p[i],0,0,2*m+i);
   }
   int ans=0;
   while (build())
      ans+=dinic(0,inf);
   return(ans==k);
}
void add(int t,int x,int y,int v,int p)
{
   a[t][0]=y,a[t][1]=v,a[t][2]=p,a[t][3]=b[x],b[x]=t;
}
int d[501];
bool build()
{
   int l,r,q[510];
   memset(d,0,sizeof(d));
   l=r=d[0]=1;
   q[1]=0;
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
         if (y==1)
            return(true);
      }
      l++;
   }
   return(false);
}
int dinic(int x,int flow)
{
   int min(int,int);
   if (x==1)
      return(flow);
   int k=flow;
   for (int i=b[x];i;i=a[i][3])
   {
      int y=a[i][0];
      if (d[y]!=d[x]+1 || !a[i][1])
         continue;
      int t=dinic(y,min(k,a[i][1]));
      k-=t;
      a[i][1]-=t;
      a[a[i][2]][1]+=t;
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
