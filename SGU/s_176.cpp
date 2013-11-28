#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,ans,b[110],a[110][110];
int main()
{
   void work();
   int check();
   int m,i,x,y,p,q;
   int f[11000][3];
   scanf("%d%d",&n,&m);
   memset(a,0,sizeof(a));
   for (i=1;i<=m;i++)
   {
      scanf("%d%d%d%d",&x,&y,&p,&q);
      f[i][0]=x;
      f[i][1]=y;
      f[i][2]=p;
      if (!q)
         a[x][y]=p;
      else
      {
         a[0][y]+=p;
         a[x][n+1]+=p;
      }
   }
   ans=0;
   work();
   a[n][1]=20000000;
   work();
   if (check())
   {
      printf("%d\n",a[1][n]);
      for (i=1;i<=m-1;i++)
         printf("%d ",f[i][2]-a[f[i][0]][f[i][1]]);
      printf("%d\n",f[m][2]-a[f[m][0]][f[m][1]]);
   }
   else
      printf("Impossible\n");   
   system("pause");
   return(0);
}
void work()
{
   int build(),dinic(int,int);
   while (build())
      ans+=dinic(0,20000000);
}
int build()
{
   int i,l,r;
   int f[110],q[110];
   memset(f,0,sizeof(f));
   l=r=1;
   q[1]=0;
   f[0]=1;
   b[0]=0;
   while (1)
   {
      for (i=0;i<=n+1;i++)
      {
         if (f[i] || !a[q[l]][i])
            continue;
         r++;
         q[r]=i;
         f[i]=1;
         b[i]=b[q[l]]+1;
         if (i==n+1)
            return(1);
      }
      l++;
      if (l>r)
         break;
   }
   return(0);
}
int dinic(int x,int flow)
{
   int min(int,int);
   int i,s,k,y;
   if (x==n+1)
      return(flow);
   s=0;
   k=flow;
   for (i=0;i<=n+1;i++)
      if (a[x][i] && b[x]+1==b[i])
      {
         y=dinic(i,min(k,a[x][i]));
         s+=y;
         k-=y;
         a[x][i]-=y;
         a[i][x]+=y;
         if (k==0)
            return(flow);
      }
   if (s==0)
      b[x]=-1;
   return(s);
}
int min(int x,int y)
{
   if (x<y)
      return(x);
   else
      return(y);
}
int check()
{
   int i,flag;
   flag=1;
   for (i=1;i<=n;i++)
      if (a[0][i]!=0)
      {
         flag=0;
         break;
      }
   return(flag);
}
