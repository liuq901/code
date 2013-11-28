#include <cstdio>
#include <cstdlib>
int a[50010];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=m;i++)
      scanf("%d",&a[i]);
   int l=1,r=n,ans;
   while (l<=r)
   {
      int mid=l+r>>1,sum=0;
      for (int i=1;i<=m;i++)
         sum+=a[i]/mid;
      if (sum>=n)
         l=mid+1,ans=mid;
      else
         r=mid-1;
   }
   printf("%d\n",ans);
   int tot=n;
   for (int i=1;i<=m;i++)
   {
      bool final=false;
      while (a[i]>=ans)
      {
         printf("%d\n",i);
         tot--;
         a[i]-=ans;
         if (!tot)
         {
            final=true;
            break;
         }
      }
      if (final)
         break;
   }
   system("pause");
   return(0);
}
