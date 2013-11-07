#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[100010];
ll s[100010];
int main()
{
   int n;
   ll S;
   scanf("%d%I64d",&n,&S);
   for (int i=1;i<=n;i++)
   {
      scanf("%d",&a[i]);
      s[i]=s[i-1]+a[i];
   }
   int now=0,ans=1<<30;
   for (int i=1;i<=n;i++)
      while (s[i]-s[now]>S)
      {
         ans=min(ans,i-now);
         now++;
      }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
