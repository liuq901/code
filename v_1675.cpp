#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,t[1001],p[1001][1001],w[1001][1001];
double f[1001][1001];
int main()
{
   void build(int);
   double calc(int,int);
   int i,m,x0,y0,x,y;
   scanf("%d%d",&n,&m);
   scanf("%d%d",&x0,&y0);
   memset(t,0,sizeof(t));
   for (i=1;i<=m;i++)
   {
      scanf("%d%d",&x,&y);
      t[x]++;
      t[y]++;
      w[x][t[x]]=y;
      w[y][t[y]]=x;
   }
   for (i=1;i<=n;i++)
      build(i);
   memset(f,0,sizeof(f));
   printf("%.3lf\n",calc(x0,y0));
   system("pause");
   return(0);
}
void build(int x)
{
   int l,r,i,tmp;
   int f[1001],q[1001],d[1001];
   memset(f,0,sizeof(f));
   memset(d,26,sizeof(d));
   f[x]=-1;
   q[1]=x;
   d[x]=0;
   l=r=1;
   while (l<=r)
   {
      for (i=1;i<=t[q[l]];i++)
      {
         tmp=w[q[l]][i];
         if (!f[tmp])
         {
            r++;
            q[r]=tmp;
            d[tmp]=d[q[l]]+1;
            f[tmp]=f[q[l]];
         }
         if (d[tmp]==d[q[l]]+1 && f[q[l]]<f[tmp])
            f[tmp]=f[q[l]];
         if (f[tmp]==-1)
            f[tmp]=tmp;
      }
      l++;
   }
   for (i=1;i<=n;i++)
      p[x][i]=f[i];
}
double calc(int x,int y)
{
   int i;
   if (f[x][y]!=0)
      return(f[x][y]);
   if (x==y)
      return(0);
   if (p[x][y]==y || p[p[x][y]][y]==y)
   {
      f[x][y]=1;
      return(1);
   }
   for (i=1;i<=t[y];i++)
      f[x][y]+=calc(p[p[x][y]][y],w[y][i]);
   f[x][y]+=calc(p[p[x][y]][y],y);
   f[x][y]/=t[y]+1;
   f[x][y]++;
   return(f[x][y]);
}
