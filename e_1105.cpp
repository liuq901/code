#include <cstdio>
#include <cstdlib>
int main()
{
   int n,m,a[1100];
   scanf("%d%d",&n,&m);
   for (int i=1;i<=m+1;i++)
      scanf("%d",&a[i]);
   int ans=0,s=n;
   for (int i=1;i<=m+1;i++)
   {
      if (a[i]>n)
      {
         printf("No Solution!\n");
         ans=-1;
         break;
      }
      if (a[i]>s)
      {
         s=n-a[i];
         ans++;
      }
      else
         s-=a[i];
   }
   if (ans!=-1)
      printf("%d\n",ans);
   system("pause");
   return(0);
}
