#include <cstdio>
#include <cstdlib>
#include <cstring>
const int inf=1000000000;
int n,a[10001][4],b[510],ans[501][35];
int main()
{
   bool build();
   int dinic(int,int);
   void get(int),print();
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int m;
      scanf("%d%d",&n,&m);
      memset(b,0,sizeof(b));
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         a[2*i-1][0]=y;
         a[2*i-1][1]=1;
         a[2*i-1][2]=2*i;
         a[2*i-1][3]=b[x];
         b[x]=2*i-1;
         a[2*i][0]=x;
         a[2*i][1]=1;
         a[2*i][2]=2*i-1;
         a[2*i][3]=b[y];
         b[y]=2*i;
      }
      int k,p[1001];
      scanf("%d",&k);
      memset(p,-1,sizeof(p));
      for (int i=1;i<=k;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         p[x]=y;
      }
      int c[501];
      memcpy(c,b,sizeof(c));
      for (int i=0;i<32;i++)
      {
         int t=m;
         memcpy(b,c,sizeof(c));
         for (int j=1;j<=n;j++)
         {
            if (p[j]==-1)
               continue;
            int x=p[j]&1;
            p[j]>>=1;
            t++;
            if (!x)
            {
               a[2*t-1][0]=n+1;
               a[2*t-1][1]=inf;
               a[2*t-1][2]=2*t;
               a[2*t-1][3]=b[j];
               b[j]=2*t-1;
               a[2*t][0]=j;
               a[2*t][1]=0;
               a[2*t][2]=2*t-1;
               a[2*t][3]=b[n+1];
               b[n+1]=2*t;
            }
            else
            {
               a[2*t-1][0]=j;
               a[2*t-1][1]=inf;
               a[2*t-1][2]=2*t;
               a[2*t-1][3]=b[0];
               b[0]=2*t-1;
               a[2*t][0]=j;
               a[2*t][1]=0;
               a[2*t][2]=2*t-1;
               a[2*t][3]=b[j];
               b[j]=2*t;
            }
         }
         while (build())
            dinic(0,inf);
         get(i);
      }
      print();
   }
   system("pause");
   return(0);
}
int d[510];
bool build()
{
   int l,r,q[510];
   memset(d,0,sizeof(d));
   q[1]=0;
   d[0]=1;
   l=r=1;
   while (l<=r)
   {
      int x=q[l],i=b[x];
      while (i)
      {
         int y=a[i][0];
         if (!d[y] && a[i][1])
         {
            d[y]=d[x]+1;
            q[++r]=y;
            if (y==n+1)
               return(true);
         }
         i=a[i][3];
      }
      l++;
   }
   return(false);
}
int dinic(int x,int flow)
{
   int min(int,int);
   if (x==n+1)
      return(flow);
   int s=0,t=flow,i=b[x];
   while (i)
   {
      if (d[a[i][0]]==d[x]+1 && a[i][1])
      {
         int k=dinic(a[i][0],min(t,a[i][1]));
         a[i][1]-=k;
         a[a[i][2]][1]+=k;
         s+=k;
         t-=k;
         if (!t)
            return(flow);
      }
      i=a[i][3];
   }
   if (!s)
      d[x]=-1;
   return(s);
}
int min(int x,int y)
{
   return(x<y?x:y);
}
void get(int p)
{
   int l,r,q[510];
   bool f[510]={0};
   f[0]=true;
   l=r=1;
   q[1]=0;
   while (l<=r)
   {
      int i=b[q[l]];
      while (i)
      {
         if (!f[a[i][0]] && a[i][1])
         {
            f[a[i][0]]=true;
            q[++r]=a[i][0];
         }
         i=a[i][3];
      }
      l++;
   }
   for (int i=1;i<=n;i++)
      ans[i][p]=f[i];
}
void print()
{
   for (int i=1;i<=n;i++)
   {
      int s=0;
      for (int j=31;j>=0;j--)
         s=(s<<1)+ans[i][j];
      printf("%d\n",s);
   }
}
