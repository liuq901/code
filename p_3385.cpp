#include <cstdio>
#include <cstdlib>
int a[100010];
int main()
{
   int n,d;
   scanf("%d%d",&n,&d);
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      a[x]++;
   }
   int ans=0;
   for (int i=0;i<=n;i++)
   {
      if (a[i]<=d)
         continue;
      while (a[i]>d)
      {
         ans+=a[i]/d;
         a[i]=a[i]/d+a[i]%d;
      }
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
