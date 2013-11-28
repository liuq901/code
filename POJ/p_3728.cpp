#include <cstdio>
#include <cstdlib>
#include <cstring>
int v[50001],d[50001],b[50001],dep[50001],a[100001][2];
int f[50001][17],mi[50001][17],ma[50001][17],ans0[50001][17],ans1[50001][17];
int main()
{
   void floodfill(int,int),init(int);
   int lca(int,int),min(int,int),max(int,int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&v[i]);
   for (int i=1;i<n;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      a[i][0]=x,a[i][1]=b[y],b[y]=i;
      a[i+n][0]=y,a[i+n][1]=b[x],b[x]=i+n;
   }
   memset(mi,26,sizeof(mi));
   memset(ma,-26,sizeof(ma));
   memset(ans0,-26,sizeof(ans0));
   memset(ans1,-26,sizeof(ans1));
   floodfill(1,0);
   for (int i=1;i<=n;i++)
      init(d[i]);
   int m;
   scanf("%d",&m);
   for (int i=1;i<=m;i++)
   {
      int x,y,p,t,min_value=1<<30,max_value=-1<<30,ans=-1<<30;
      scanf("%d%d",&x,&y);
      int z=lca(x,y);
      p=x,t=16;
      while (p!=z)
      {
         while (dep[f[p][t]]<dep[z])
            t--;
         ans=max(ans,max(ans0[p][t],ma[p][t]-min_value));
         min_value=min(min_value,mi[p][t]);
         p=f[p][t];
      }
      p=y,t=16;
      while (p!=z)
      {
         while (dep[f[p][t]]<dep[z])
            t--;
         ans=max(ans,max(ans1[p][t],max_value-mi[p][t]));
         max_value=max(max_value,ma[p][t]);
         p=f[p][t];
      }
      ans=max(ans,max_value-min_value);
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void floodfill(int x,int father)
{
   dep[x]=dep[father]+1;
   f[x][0]=father;
   d[++d[0]]=x;
   for (int i=b[x];i;i=a[i][1])
   {
      if (a[i][0]==father)
         continue;
      floodfill(a[i][0],x);
   }
}
void init(int x)
{
   int min(int,int),max(int,int);
   int p=f[x][0];
   mi[x][0]=min(v[x],v[f[x][0]]);
   ma[x][0]=max(v[x],v[f[x][0]]);
   ans0[x][0]=max(0,v[f[x][0]]-v[x]);
   ans1[x][0]=max(0,v[x]-v[f[x][0]]);
   for (int i=1;i<=16;i++)
   {
      mi[x][i]=min(mi[x][i-1],mi[p][i-1]);
      ma[x][i]=max(ma[x][i-1],ma[p][i-1]);
      ans0[x][i]=max(max(ans0[x][i-1],ans0[p][i-1]),ma[p][i-1]-mi[x][i-1]);
      ans1[x][i]=max(max(ans1[x][i-1],ans1[p][i-1]),ma[x][i-1]-mi[p][i-1]);
      p=f[p][i-1];
      f[x][i]=p;
   }
}
int min(int x,int y)
{
   return(x<y?x:y);
}
int max(int x,int y)
{
   return(x>y?x:y);
}
int lca(int x,int y)
{
   int t;
   if (dep[x]<dep[y])
      t=x,x=y,y=t;
   t=16;
   while (dep[x]!=dep[y])
   {
      while (dep[f[x][t]]<dep[y])
         t--;
      x=f[x][t];
   }
   t=16;
   while (x!=y)
   {
      while (t>=1 && f[x][t]==f[y][t])
         t--;
      x=f[x][t],y=f[y][t];
   }
   return(x);
}
