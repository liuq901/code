#include <cstdio>
#include <cstdlib>
#include <cstring>
const double epsilon=1e-8;
int n,m,e[401][3];
int main()
{
   double work(double);
   void print(double);
   while (scanf("%d%d",&n,&m)!=EOF)
   {
      double max=0;
      for (int i=1;i<=m;i++)
      {
         scanf("%d%d%d",&e[i][0],&e[i][1],&e[i][2]);
         if (e[i][2]>max)
            max=e[i][2];
      }
      double left=0,right=max;
      while (right-left>epsilon)
      {
         double mid=(left+right)/2;
         if (work(mid)>0)
            left=mid;
         else
            right=mid;
      }
      print(left);
   }
   system("pause");
   return(0);
}
double a[101][101];
double work(double mid)
{
   bool build();
   double dinic(int,double);
   double ans=0;
   memset(a,0,sizeof(a));
   for (int i=1;i<=m;i++)
   {
      if (e[i][2]<mid)
      {
         ans+=e[i][2]-mid;
         continue;
      }
      int x=e[i][0],y=e[i][1];
      a[x][y]+=e[i][2]-mid;
      a[y][x]+=e[i][2]-mid;
   }
   while (build())
      ans+=dinic(1,1e10);
   return(ans);
}
int d[101];
bool build()
{
   int l,r,q[101];
   bool f[101]={0};
   l=r=1;
   q[1]=d[1]=1;
   f[1]=true;
   while (l<=r)
   {
      int x=q[l];
      for (int i=1;i<=n;i++)
      {
         if (f[i] || a[x][i]<epsilon)
            continue;
         d[i]=d[x]+1;
         f[i]=true;
         q[++r]=i;
         if (i==n)
            return(true);
      }
      l++;
   }
   return(false);
}
double dinic(int x,double flow)
{
   double min(double,double);
   if (x==n)
      return(flow);
   double s=0,t=flow;
   for (int i=1;i<=n;i++)
   {
      if (d[i]!=d[x]+1 || a[x][i]<epsilon)
         continue;
      double k=dinic(i,min(t,a[x][i]));
      a[x][i]-=k;
      a[i][x]+=k;
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
void print(double mid)
{
   int l,r,ans[401],q[101];
   bool f[101]={0};
   f[1]=true;
   q[1]=1;
   l=r=1;
   while (l<=r)
   {
      int x=q[l];
      for (int i=1;i<=n;i++)
      {
         if (f[i] || a[x][i]<epsilon)
            continue;
         f[i]=true;
         q[++r]=i;
      }
      l++;
   }
   ans[0]=0;
   for (int i=1;i<=m;i++)
   {
      if (e[i][2]<mid)
      {
         ans[++ans[0]]=i;
         continue;
      }
      int x=e[i][0],y=e[i][1];
      if (f[x] && !f[y] || f[y] && !f[x])
         ans[++ans[0]]=i;
   }
   printf("%d\n",ans[0]);
   for (int i=1;i<=ans[0]-1;i++)
      printf("%d ",ans[i]);
   if (ans[0])
      printf("%d\n",ans[ans[0]]);
   printf("\n");
}
