#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[60];
int main()
{
   while (1)
   {
      int n,Q;
      scanf("%d%d",&n,&Q);
      if (!n && !Q)
         break;
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      while (Q--)
      {
         int m;
         scanf("%d",&m);
         int low=0,high=1<<30;
         for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
               for (int k=j+1;k<=n;k++)
                  for (int l=k+1;l<=n;l++)
                  {
                     int p=a[i]/__gcd(a[i],a[j])*a[j];
                     p=p/__gcd(p,a[k])*a[k],p=p/__gcd(p,a[l])*a[l];
                     int len=m/p*p;
                     low=max(low,len);
                     if (len!=m)
                        len+=p;
                     high=min(high,len);
                  }
         printf("%d %d\n",low,high);
      }
   }
   system("pause");
   return(0);
}
