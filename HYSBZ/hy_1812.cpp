#include <cstdio>
#include <cstdlib>
#include <cstring>
const int inf=20000000;
int l[101],r[101],v[101],a[101],b[101],dist[101][101],f[101][101][55];
int main()
{
   int solve(int,int,int);
   int n,k;
   scanf("%d%d",&n,&k);
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d%d%d",&v[i],&x,&a[i]);
      b[i]=x;
      if (!l[x])
         l[x]=i;
      else
      {
         int t=l[x];
         while (r[t])
            t=r[t];
         r[t]=i;
      }
   }
   memset(f,-1,sizeof(f));
   memset(dist,-1,sizeof(dist));
   printf("%d\n",solve(0,0,k));
   system("pause");
   return(0);
}
int solve(int x,int father,int sum)
{
   int count(int,int);
   if (f[x][father][sum]!=-1)
      return(f[x][father][sum]);
   if (!l[x] && !r[x])
   {
      if (!sum)
         f[x][father][sum]=v[x]*count(x,father);
      else if (sum==1)
         f[x][father][sum]=0;
      else
         f[x][father][sum]=inf;
      return(f[x][father][sum]);
   }
   if (!l[x])
   {
      int t,ans=inf;
      t=solve(r[x],father,sum)+v[x]*count(x,father);
      if (t<ans)
         ans=t;
      t=solve(r[x],father,sum-1);
      if (t<ans)
         ans=t;
      f[x][father][sum]=ans;
      return(ans);
   }
   if (!r[x])
   {
      int t,ans=inf;
      t=solve(l[x],father,sum)+v[x]*count(x,father);
      if (t<ans)
         ans=t;
      t=solve(l[x],x,sum-1);
      if (t<ans)
         ans=t;
      f[x][father][sum]=ans;
      return(ans);
   }
   int ans=inf;
   for (int i=0;i<=sum;i++)
   {
      int t;
      if (i)
      {
         t=solve(l[x],x,i-1)+solve(r[x],father,sum-i);
         if (t<ans)
            ans=t;
      }
      t=solve(l[x],father,i)+solve(r[x],father,sum-i)+v[x]*count(x,father);
      if (t<ans)
         ans=t;
   }
   f[x][father][sum]=ans;
   return(ans);
}
int count(int x,int y)
{
   if (dist[x][y]!=-1)
      return(dist[x][y]);
   dist[x][y]=0;
   for (int i=x;i!=y;i=b[i])
      dist[x][y]+=a[i];
   return(dist[x][y]);
}
