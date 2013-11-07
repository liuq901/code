#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,b[210],a[210][210];
int main()
{
   void did();
   int t;
   scanf("%d",&t);
   while (t--)
      did();
   system("pause");
   return(0);
}
void did()
{
   void work();
   int check();
   int m,x,y,p,q,i,j;
   int f[40001][3];
   scanf("%d%d",&n,&m);
   memset(a,0,sizeof(a));
   for (i=1;i<=m;i++)
   {
      scanf("%d%d%d%d",&x,&y,&p,&q);
      f[i][0]=x;
      f[i][1]=y;
      f[i][2]=p;
      a[x][y]=q-p;
      a[0][y]+=p;
      a[x][n+1]+=p;
   }
   work();
   if (!check())
      printf("NO\n");
   else
   {
      printf("YES\n");
      for (i=1;i<=m;i++)
         printf("%d\n",a[f[i][1]][f[i][0]]+f[i][2]);
   }
   printf("\n");
}
void work()
{
   int build(),dinic(int,int);
   while (build())
      dinic(0,20000000);
}
int build()
{
   int l,r,i;
   int q[210],f[210];
   memset(f,0,sizeof(f));
   f[0]=1;
   l=r=1;
   q[1]=0;
   b[0]=0;
   while (1)
   {
      for (i=1;i<=n+1;i++)
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
