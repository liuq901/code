#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
   void work();
   int t;
   scanf("%d",&t);
   for (int i=1;i<=t;i++)
      work();
   system("pause");
   return(0);
}
void work()
{
   int n,a,b;
   scanf("%d%d%d",&n,&a,&b);
   int p[10001];
   for (int i=1;i<=n;i++)
      scanf("%d",&p[i]);
   sort(p+1,p+n+1);
   int f[10001];
   memset(f,-26,sizeof(f));
   for (int i=n;i>=1;i--)
   {
      bool flag=false;
      for (int j=i+1;j<=n;j++)
         if (p[j]-p[i]>=a && p[j]-p[i]<=b)
         {
            flag=true;
            if (f[j]>f[i])
               f[i]=f[j];
         }
      if (!flag)
         f[i]=0;
      f[i]=p[i]-f[i];
   }
   int ans=-20000000;
   bool flag=false;
   for (int i=1;i<=n;i++)
      if (p[i]>=a && p[i]<=b)
      {
         flag=true;
         if (f[i]>ans)
            ans=f[i];
      }
   if (!flag)
      ans=0;
   printf("%d\n",ans);
}
