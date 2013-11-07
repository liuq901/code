#include <cstdio>
#include <cstdlib>
#include <cstring>
int ans[10001],link[10001],b[10001],a[20001][2];
bool f[10001];
int main()
{
   bool hungary(int);
   int n,t=0;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      int p;
      scanf("%d",&p);
      int x=i-p,y=i+p;
      if (x<=0)
         x+=n;
      if (y>n)
         y-=n;
      if (x>y)
      {
         int t;
         t=x,x=y,y=t;
      }
      a[++t][0]=y,a[t][1]=b[i],b[i]=t;
      a[++t][0]=x,a[t][1]=b[i],b[i]=t;
   }
   bool flag=false;
   for (int i=n;i;i--)
   {
      memset(f,0,sizeof(f));
      if (!hungary(i))
      {
         flag=true;
         break;
      }
   }
   if (flag)
      printf("No Answer\n");
   else
   {
      for (int i=1;i<=n;i++)
         ans[link[i]]=i-1;
      for (int i=1;i<n;i++)
         printf("%d ",ans[i]);
      printf("%d\n",ans[n]);
   }
   system("pause");
   return(0);
}
bool hungary(int x)
{
   if (!x)
      return(true);
   for (int i=b[x];i;i=a[i][1])
   {
      int y=a[i][0];
      if (f[y])
         continue;
      f[y]=true;
      if (hungary(link[y]))
      {
         link[y]=x;
         return(true);
      }
   }
   return(false);
}
