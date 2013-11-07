#include <cstdio>
#include <cstdlib>
#include <cstring>
const int inf=100000000;
bool way[1025];
int p,n,c[1025],l[2100],r[2100],a[1025][1025],g[1025][2100],f[2048][2100];
int main()
{
   void init(int),build(int,int);
   int solve(int,int,int,int);
   int m;
   scanf("%d",&m);
   n=1<<m;
   p=(1<<m)-1;
   for (int i=1;i<=n;i++)
      scanf("%d",&way[i]);
   for (int i=1;i<=n;i++)
      scanf("%d",&c[i]);
   for (int i=1;i<=n;i++)
      for (int j=i+1;j<=n;j++)
      {
         scanf("%d",&a[i][j]);
         a[j][i]=a[i][j];
      }
   init(1);
   for (int i=1;i<=n;i++)
      build(1,i);
   int ans=inf;
   memset(f,-1,sizeof(f));
   for (int i=0;i<=n;i++)
   {
      int t=solve(1,i,0,n);
      if (t<ans)
         ans=t;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void init(int x)
{   
   if (x>p)
      return;
   l[x]=2*x;
   r[x]=2*x+1;
   init(l[x]);
   init(r[x]);
}
void build(int x,int k)
{
   if (!l[x])
   {
      g[k][x]=a[k][x-p];
      return;
   }
   build(l[x],k);
   build(r[x],k);
   g[k][x]=g[k][l[x]]+g[k][r[x]];
}
int solve(int x,int y,int z,int sum)
{
   int get(int,int);
   if (y>sum)
      return(inf);
   int time=0,tmp=sum;
   while (tmp)
   {
      time++;
      tmp/=2;
   }
   if (f[x][(z<<time)+y]!=-1)
      return(f[x][(z<<time)+y]);
   if (sum==1)
   {
      int ans=0,i=x/2,j=x,k=z;
      while (i)
      {
         bool flag=k&1;
         if (flag==1-y)
         {
            int t;
            if (2*i==j)
               t=2*i+1;
            else
               t=2*i;
            ans+=g[x-p][t];
         }
         j=i;
         i/=2;
         k/=2;
      }
      if (way[x-p]!=1-y)
         ans+=c[x-p];
      f[x][(z<<time)+y]=ans;
      return(ans);
   }
   int t=sum-y;
   tmp=z;
   if (y<t)
      z<<=1;
   else
      z=(z<<1)+1;
   int ans=inf;
   for (int i=0;i<=y;i++)
   {
      int t=solve(l[x],i,z,sum/2)+solve(r[x],y-i,z,sum/2);
      if (t<ans)
         ans=t;
   }
   f[x][(tmp<<time)+y]=ans;
   return(ans);
}
int get(int x,int y)
{
   int s=0;
   while (x!=y)
   {
      s++;
      x/=2;
      y/=2;
   }
   return(s);
}
