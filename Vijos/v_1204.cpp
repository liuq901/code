#include <cstdio>
#include <cstdlib>
int link[101],b[101],a[100001][2];
bool f[101];
int main()
{
   bool hungary(int);
   int n,m,tot=0;
   scanf("%d%d%*c",&n,&m);
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=m;j++)
      {
         char ch;
         scanf("%c",&ch);
         if (ch=='1')
            a[++tot][0]=j,a[tot][1]=b[i],b[i]=tot;
      }
      scanf("%*c");
   }
   int ans=0;
   for (int i=1;i<=n;i++)
      if (hungary(i))
         ans++;
   printf("%d\n",ans);
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
