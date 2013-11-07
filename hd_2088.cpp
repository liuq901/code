#include <cstdio>
#include <cstdlib>
int a[60];
int main()
{
   bool first=true;
   while (1)
   {
      int n,sum=0;
      scanf("%d",&n);
      if (!n)
         break;
      for (int i=1;i<=n;i++)
      {
         scanf("%d",&a[i]);
         sum+=a[i];
      }
      sum/=n;
      int ans=0;
      for (int i=1;i<=n;i++)
         ans+=abs(a[i]-sum);
      if (!first)
         printf("\n");
      first=false;
      printf("%d\n",ans>>1);
   }
   system("pause");
   return(0);
}
