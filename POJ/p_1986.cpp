#include <cstdio>
#include <cstdlib>
#include <cmath>
int b[40001],l[40001],p[40001],e[80001],d[80001],a[80001][3],f[20][80001];
int main()
{
   void floodfill(int,int,int),init(int);
   int lca(int,int);
   int n;
   scanf("%d%*d",&n);
   for (int i=1;i<n;i++)
   {
      int x,y,z;
      scanf("%d%d%d %*c",&x,&y,&z);
      a[i][0]=y;
      a[i][1]=z;
      a[i][2]=b[x];
      b[x]=i;
      a[i+n][0]=x;
      a[i+n][1]=z;
      a[i+n][2]=b[y];
      b[y]=i+n;
   }
   l[1]=0;
   floodfill(1,0,1);
   init(2*n-1);
   int m;
   scanf("%d",&m);
   while (m--)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      int z=lca(x,y);
      printf("%d\n",l[x]+l[y]-2*l[z]);
   }
   system("pause");
   return(0);
}
void floodfill(int x,int father,int dep)
{
   e[++e[0]]=x;
   p[x]=e[0];
   d[e[0]]=dep;
   for (int i=b[x];i;i=a[i][2])
   {
      int y=a[i][0];
      if (y==father)
         continue;
      l[y]=l[x]+a[i][1];
      floodfill(y,x,dep+1);
      e[++e[0]]=x;
      d[e[0]]=dep;
   }
}
void init(int n)
{
   int log(int);
   for (int i=1;i<=n;i++)
      f[0][i]=i;
   int m=log(n);
   for (int i=1;i<=m;i++)
      for (int j=1;j<=n;j++)
      {
         int t=1<<i-1;
         if (j+t>n)
            break;
         f[i][j]=d[f[i-1][j]]<d[f[i-1][j+t]]?f[i-1][j]:f[i-1][j+t];
      }
}
int lca(int x,int y)
{
   int log(int);
   x=p[x],y=p[y];
   if (x>y)
   {
      int t;
      t=x,x=y,y=t;
   }
   int t=log(y-x+1),k=1<<t;
   return(d[f[t][x]]<d[f[t][y-k+1]]?e[f[t][x]]:e[f[t][y-k+1]]);
}
int log(int x)
{
   int ans=0;
   while (x)
   {
      ans++;
      x>>=1;
   }
   return(ans-1);
}
