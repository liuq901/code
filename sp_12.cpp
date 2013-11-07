#include <cstdio>
#include <cstdlib>
#include <cstring>
int time,m,p,c,flag,a[11],b[101],w[101],g[101][11];
int main()
{
   void work();
   int i,t;
   scanf("%d",&t);
   for (i=1;i<=t;i++)
      work();
   system("pause");
   return(0);
}
void work()
{
   void search(int);
   int i,j;
   scanf("%d%d%d",&p,&c,&m);
   memset(b,0,sizeof(b));
   for (i=1;i<=m;i++)
   {
      for (j=1;j<=p;j++)
         scanf("%d",&g[i][j]);
      scanf("%d%d",&b[i],&w[i]);
   }
   flag=time=0;
   search(1);
   if (!flag)
      printf("You are cheating!\n");
}
void search(int t)
{
   int check(int);
   int i;
   time++;
   if (time>10000)
      return;
   if (t>p)
   {
      for (i=1;i<=p-1;i++)
         printf("%d ",a[i]);
      printf("%d\n",a[p]);
      flag=1;
      return;
   }
   for (i=1;i<=c;i++)
   {
      a[t]=i;
      if (check(t))
      {
         search(t+1);
         if (flag)
            return;
      }
   }
}
int check(int t)
{
   int min(int,int);
   int i,j,x,y;
   int f[2][101];
   for (i=1;i<=m;i++)
   {
      x=y=0;
      memset(f,0,sizeof(f));
      for (j=1;j<=t;j++)
         if (a[j]==g[i][j])
            x++;
         else
         {
            f[0][g[i][j]]++;
            f[1][a[j]]++;
         }
      for (j=1;j<=c;j++)
         y+=min(f[0][j],f[1][j]);
      if (t==p && (x!=b[i] || y!=w[i]))
         return(0);
      if (x>b[i] || y>w[i])
         return(0);
   }
   return(1);
}
int min(int x,int y)
{
   if (x<y)
      return(x);
   else
      return(y);
}
