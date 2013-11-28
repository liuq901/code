#include <cstdio>
#include <cstdlib>
#include <cstring>
const double inf=1e10,epsilon=1e-5;
int p,b[2001],a[10001][3],e[1001][2];
double v[10001];
int main()
{
   bool build();
   double dinic(int,double);
   void print(int);
   int n,m;
   scanf("%d%d",&n,&m);
   if (!m)
      printf("1\n1\n");
   else
   {
      p=n+m+1;
      for (int i=1;i<=m;i++)
         scanf("%d%d",&e[i][0],&e[i][1]);
      double l,r;
      l=0;
      r=m;
      while (r-l>1e-10)
      {
         double sum=0,mid=(l+r)/2;
         memset(b,0,sizeof(b));
         for (int i=1;i<=n;i++)
         {
            a[2*i-1][0]=p;
            a[2*i-1][1]=2*i;
            a[2*i-1][2]=b[i];
            v[2*i-1]=mid;
            b[i]=2*i-1;
            a[2*i][0]=i;
            a[2*i][1]=2*i-1;
            a[2*i][2]=b[p];
            v[2*i]=0;
            b[p]=2*i;
         }
         int t=n;
         for (int i=1;i<=m;i++)
         {
            t++;
            a[2*t-1][0]=n+i;
            a[2*t-1][1]=2*t;
            a[2*t-1][2]=b[0];
            v[2*t-1]=1;
            b[0]=2*t-1;
            a[2*t][0]=0;
            a[2*t][1]=2*t-1;
            a[2*t][2]=b[n+i];
            b[n+i]=2*t;
            int x=e[i][0],y=e[i][1];
            t++;
            a[2*t-1][0]=x;
            a[2*t-1][1]=2*t;
            a[2*t-1][2]=b[n+i];
            v[2*t-1]=inf;
            b[n+i]=2*t-1;
            a[2*t][0]=n+i;
            a[2*t][1]=2*t-1;
            a[2*t][2]=b[x];
            v[2*t]=0;
            b[x]=2*t;
            t++;
            a[2*t-1][0]=y;
            a[2*t-1][1]=2*t;
            a[2*t-1][2]=b[n+i];
            v[2*t-1]=inf;
            b[n+i]=2*t-1;
            a[2*t][0]=n+i;
            a[2*t][1]=2*t-1;
            a[2*t][2]=b[y];
            v[2*t]=0;
            b[y]=2*t;
         }
         while (build())
            sum+=dinic(0,inf);
         if (m-sum>0)
            l=mid;
         else
            r=mid;
      }
      print(n);
   }
   system("pause");
   return(0);
}
int d[2001];
bool build()
{
   int l,r,q[2001];
   memset(d,0,sizeof(d));
   l=r=1;
   q[1]=0;
   d[0]=1;
   while (l<=r)
   {
      int x=q[l],i=b[x];
      while (i)
      {
         int y=a[i][0];
         if (!d[y] && v[i]>epsilon)
         {
            d[y]=d[x]+1;
            q[++r]=y;
            if (y==p)
               return(true);
         }
         i=a[i][2];
      }
      l++;
   }
   return(false);
}
double dinic(int x,double flow)
{
   double min(double,double);
   if (x==p)
      return(flow);
   double s=0,t=flow;
   for (int i=b[x];i;i=a[i][2])
   {
      if (d[a[i][0]]!=d[x]+1 || v[i]<epsilon)
         continue;
      double k=dinic(a[i][0],min(t,v[i]));
      v[i]-=k;
      v[a[i][1]]+=k;
      s+=k;
      t-=k;
      if (t<epsilon)
         return(flow);
   }
   if (s<epsilon)
      d[x]=-1;
   return(s);
}
double min(double x,double y)
{
   return(x<y?x:y);
}
void print(int n)
{
   bool search(int,int,int);
   int l,r,ans[101],q[2010];
   bool f[2010]={0};
   l=r=1;
   q[1]=p;
   f[p]=true;
   while (l<=r)
   {
      int x=q[l];
      for (int i=b[x];i;i=a[i][2])
         if (!f[a[i][0]] && v[a[i][1]]>epsilon)
         {
            f[a[i][0]]=true;
            q[++r]=a[i][0];
         }
      l++;
   }
   ans[0]=0;
   for (int i=1;i<=n;i++)
      if (!f[i])
         ans[++ans[0]]=i;
   printf("%d\n",ans[0]);
   for (int i=1;i<=ans[0];i++)
      printf("%d\n",ans[i]);
}
