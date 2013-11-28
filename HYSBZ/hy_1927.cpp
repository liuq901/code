#include <cstdio>
#include <cstdlib>
#include <cstring>
const int inf=1<<30;
int tot=1,sum,b[1610],a[40000][4];
long long d[1610];
int main()
{
   void add(int,int,int);
   long long spfa();
   int n,m;
   scanf("%d%d",&n,&m);
   sum=(n<<1)+1;
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      add(0,i,x);
      add(i,i+n,-inf);
      add(i+n,sum,0);
   }
   for (int i=1;i<=m;i++)
   {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      if (x>y)
      {
         int t;
         t=x,x=y,y=t;
      }
      add(x+n,y,z);
   }
   long long ans=1LL<<60,cost=0;
   while (1)
   {
      cost+=spfa();
      if (d[sum]>=0)
         break;
      if (cost<ans)
         ans=cost;
   }
   printf("%I64d\n",ans+(long long)inf*n);
   system("pause");
   return(0);
}
void add(int x,int y,int v)
{
   a[++tot][0]=y,a[tot][1]=1,a[tot][2]=v,a[tot][3]=b[x],b[x]=tot;
   a[++tot][0]=x,a[tot][1]=0,a[tot][2]=-v,a[tot][3]=b[y],b[y]=tot;
}
long long spfa()
{
   int min(int,int);
   memset(d,26,sizeof(d));
   d[0]=0;
   int l,r,q[1610],pre[1610],p[1610];
   bool f[1610]={0};
   l=0,r=1;
   q[1]=0;
   f[0]=true;
   while (l!=r)
   {
      l=l==sum?1:l+1;
      int x=q[l];
      for (int i=b[x];i;i=a[i][3])
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
               r=r==sum?1:r+1;
               q[r]=y;
               int k=l==sum?1:l+1;
               if (d[q[r]]<d[q[k]])
               {
                  int t;
                  t=q[r],q[r]=q[k],q[k]=t;
               }
            }
         }
      }
      f[x]=false;
   }
   if (d[sum]>=0)
      return(inf);
   int flow=inf;
   for (int i=sum;i;i=pre[i])
      flow=min(flow,a[p[i]][1]);
   for (int i=sum;i;i=pre[i])
   {
      a[p[i]][1]-=flow;
      a[p[i]^1][1]+=flow;
   }
   return(d[sum]*flow);
}
int min(int x,int y)
{
   return(x<y?x:y);
}
