#include <cstdio>
#include <cstdlib>
int k,t,d[10001],c[10001],b[10001],ans[10001],a[20001][2];
int main()
{
   void floodfill(int,int),dfs(int,int,int);
   int n;
   scanf("%d",&n);
   for (int i=2;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      a[i][0]=i,a[i][1]=b[x],b[x]=i;
      a[i+n][0]=x,a[i+n][1]=b[i],b[i]=i+n;
   }
   d[0]=-1;
   k=0;
   floodfill(1,0);
   t=k,k=0;
   floodfill(t,0);
   dfs(t,0,d[k]+1>>1);
   t=k;
   floodfill(t,0);
   dfs(t,0,d[k]+1>>1);
   for (int i=1;i<=n;i++)
      if (c[i]==2)
         ans[++ans[0]]=i;
   for (int i=1;i<ans[0];i++)
      printf("%d ",ans[i]);
   printf("%d\n",ans[ans[0]]);
   system("pause");
   return(0);
}
void floodfill(int x,int father)
{
   d[x]=d[father]+1;
   if (d[x]>d[k])
      k=x;
   for (int i=b[x];i;i=a[i][1])
   {
      if (a[i][0]==father)
         continue;
      floodfill(a[i][0],x);
   }
}
void dfs(int x,int father,int cost)
{
   if (d[x]>cost)
      return;
   c[x]++;
   for (int i=b[x];i;i=a[i][1])
   {
      if (a[i][0]==father)
         continue;
      dfs(a[i][0],x,cost);
   }
}
