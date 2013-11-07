#include <cstdio>
#include <cstdlib>
#include <cstring>
bool f[1000001];
int b[10010],link[1000001],a[2000001][2];
int main()
{
   bool hungary(int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      a[i][0]=i,a[i][1]=b[x],b[x]=i;
      a[i+n][0]=i,a[i+n][1]=b[y],b[y]=i+n;
   }
   for (int i=1;i<=10001;i++)
      if (!hungary(i))
      {
         printf("%d\n",i-1);
         break;
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
         f[y]=false;
         link[y]=x;
         return(true);
      }
   }
   return(false);
}
