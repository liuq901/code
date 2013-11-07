#include <cstdio>
#include <cstdlib>
int a[400001][3],d[200001],b[200001],f[200001];
long long ans,v[200001][2];
int main()
{
   void work();
   int t;
   scanf("%d",&t);
   while (t--)
      work();
   system("pause");
   return(0);
}
void work()
{
   long long floodfill(int,int);
   void tree_dp(int,int,long long);
   int n;
   scanf("%d%*d",&n);
   for (int i=1;i<=n-1;i++)
   {
      int x,y,t;
      scanf("%d%d%d",&x,&y,&t);
      a[i][0]=y;
      a[i][1]=t;
      a[i][2]=b[x];
      b[x]=i;
      a[i+n][0]=x;
      a[i+n][1]=t;
      a[i+n][2]=b[y];
      b[y]=i+n;
      d[x]++;
      d[y]++;
   }
   int root,max=0;
   for (int i=1;i<=n;i++)
      if (d[i]==1 && a[b[i]][1]>max)
      {
         root=i;
         max=a[b[i]][1];
      }
   floodfill(root,0);
   tree_dp(root,0,0);
   printf("%lld\n",ans);
}
long long floodfill(int x,int father)
{
   v[x][0]=v[x][1]=0;
   f[x]=x;
   for (int i=b[x];i;i=a[i][2])
   {
      if (a[i][0]==father)
         continue;
      long long t=floodfill(a[i][0],x)+a[i][1];
      if (t>v[x][1])
         v[x][1]=t;
      if (v[x][1]>v[x][0])
      {
         f[x]=a[i][0];
         long long t;
         t=v[x][0],v[x][0]=v[x][1],v[x][1]=t;
      }
   }
   return(v[x][0]);
}
void tree_dp(int x,int father,long long max)
{
   long long t1,t2,t3;
   t1=v[x][0],t2=v[x][1],t3=max;
   if (t3>t2)
   {
      long long t;
      t=t2,t2=t3,t3=t;
   }
   if (t2>t1)
   {
      long long t;
      t=t2,t2=t1,t1=t;
   }
   if (t1+2*t2+t3>ans)
      ans=t1+2*t2+t3;
   for (int i=b[x];i;i=a[i][2])
   {
      if (a[i][0]==father)
         continue;
      long long t;
      if (f[x]!=a[i][0])
         t=v[x][0];
      else
         t=v[x][1];
      if (t>max)
         tree_dp(a[i][0],x,t+a[i][1]);
      else
         tree_dp(a[i][0],x,max+a[i][1]);
   }
}
