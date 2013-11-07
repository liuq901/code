#include <cstdio>
#include <cstdlib>
int a[100010];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   for (int i=1;i<=m;i++)
   {
      int x;
      scanf("%d",&x);
      int l=1,r=n,ans=0;
      while (l<=r)
      {
         int mid=l+r>>1;
         if (a[mid]==x)
         {
            ans=mid;
            break;
         }
         if (a[mid]<x)
            l=mid+1;
         else
            r=mid-1;
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
