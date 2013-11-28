#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
   int n,a[101],b[101],c[101];
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d%d%d",&a[i],&b[i],&c[i]);
   for (int i=1;i<n;i++)
      for (int j=i+1;j<=n;j++)
         if (a[i]>a[j])
         {
            swap(a[i],a[j]);
            swap(b[i],b[j]);
            swap(c[i],c[j]);
         }
   int t,ans;
   t=ans=0;
   for (int i=1;i<=n;i++)
   {
      t=max(t,a[i])+b[i];
      ans=max(ans,t-c[i]);
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
