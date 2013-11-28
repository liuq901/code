#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
char s[200010];
int a[200010];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      scanf("%s",s+1);
      int n=strlen(s+1);
      for (int i=1;i<=n;i++)
         s[i+n]=s[i];
      int sum=0;
      for (int i=1;i<=n<<1;i++)
      {
         a[i]=a[i-1];
         if (s[i]=='A')
         {
            a[i]++;
            sum++;
         }
      }
      sum>>=1;
      int ans=1<<30;
      for (int i=0;i<n;i++)
         ans=min(ans,sum-(a[i+sum]-a[i]));
      static int id=0;
      printf("Case %d: %d\n",++id,ans);
   }
   system("pause");
   return(0);
}
