#include <cstdio>
#include <cstdlib>
int main()
{
   int n,m,p,i,j,x,y;
   int a[5001];
   scanf("%d%d%d",&n,&m,&p);
   for (i=1;i<=n;i++)
      a[i]=i;
   for (i=1;i<=m;i++)
   {
      scanf("%d%d",&x,&y);
      for (j=1;j<=n;j++)
         if (a[y]==a[j] && y!=j)
            a[j]=a[x];
      a[y]=a[x];
   }
   for (i=1;i<=p;i++)
   {
      scanf("%d%d",&x,&y);
      if (a[x]==a[y])
         printf("Yes\n");
      else
         printf("No\n");
   }
   system("pause");
   return(0);
}
