#include <cstdio>
#include <cstdlib>
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (n==0)
         break;
      int s=0,a[1001];
      for (int i=1;i<=n;i++)
      {
         scanf("%d",&a[i]);
         s^=a[i];
      }
      int ans=0;
      for (int i=1;i<=n;i++)
      {
         int t=s^a[i];
         if (t<a[i])
            ans++;
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
