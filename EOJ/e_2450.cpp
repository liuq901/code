#include <cstdio>
#include <cstdlib>
int a[100010],q[100010];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,k;
      scanf("%d%d",&n,&k);
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      int l,r;
      l=1,r=0;
      for (int i=1;i<k;i++)
      {
         int x=a[i];
         while (l<=r && a[q[r]]<=x)
            r--;
         q[++r]=i;
      }
      for (int i=k;i<=n;i++)
      {
         if (q[l]<=i-k)
            l++;
         int x=a[i];
         while (l<=r && a[q[r]]<=x)
            r--;
         q[++r]=i;
         printf("%d%c",a[q[l]],i==n?'\n':' ');
      }
   }
   system("pause");
   return(0);
}
