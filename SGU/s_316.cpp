#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int n,m,i,x,y;
   int a[10],b[10];
   scanf("%d%d",&n,&m);
   for (i=1;i<=n;i++)
      a[i]=100;
   memset(b,0,sizeof(b));
   for (i=1;i<=m;i++)
   {
      scanf("%d%d",&x,&y);
      if (a[x]<=0)
         continue;
      if (a[y]>0)
         b[x]+=3;
      a[y]-=8;
   }
   for (i=1;i<=n;i++)
   {
      if (a[i]>0)
         b[i]+=a[i]/2;
      printf("%d %d\n",a[i],b[i]);
   }
   system("pause");
   return(0);
}
