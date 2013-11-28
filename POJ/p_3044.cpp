#include <cstdio>
#include <cstdlib>
int main()
{
   int i,n,x,ans,t;
   int a[50001];
   scanf("%d%*d",&n);
   a[0]=-1;
   ans=t=0;
   for (i=1;i<=n;i++)
   {
      scanf("%*d%d",&x);
      if (x>a[t])
      {
         t++;
         a[t]=x;
      }
      else
      {
         while (x<a[t])
         {
            t--;
            ans++;
         }
         if (x!=a[t])
         {
            t++;
            a[t]=x;
         }
      }
   }
   while (a[t]>0)
   {
      t--;
      ans++;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
