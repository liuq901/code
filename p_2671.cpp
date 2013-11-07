#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[610],b[610];
ll s[610],t[610],f[610][610],g[610][610];
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      ll sum=0;
      for (int i=0;i<n;i++)
      {
         scanf("%d%d",&a[i],&b[i]);
         a[i+n]=a[i],b[i+n]=b[i];
         sum+=a[i];
      }
      n<<=1;
      for (int i=1;i<n;i++)
      {
         s[i]=s[i-1]+a[i];
         t[i]=t[i-1]+b[i-1];
      }
      memset(f,63,sizeof(f));
      memset(g,63,sizeof(g));
      f[n>>1][n>>1]=g[n>>1][n>>1]=0;
      ll ans=1LL<<60;
      for (int i=n-1;i;i--)
         for (int j=i;j<n;j++)
         {
            if (j-i==(n>>1)-1)
            {
               ans=min(ans,min(f[i][j],g[i][j]));
               continue;
            }
            if (j-i>(n>>1)-1)
               break;
            ll x=sum-(s[j]-s[i-1]);
            f[i-1][j]=min(f[i-1][j],min(x*b[i-1]+f[i][j],x*(t[j]-t[i-1])+g[i][j]));
            g[i][j+1]=min(g[i][j+1],min(x*(t[j+1]-t[i])+f[i][j],x*b[j]+g[i][j]));
         }
      printf("%d\n",int(ans));
   }
   system("pause");
   return(0);
}
