#include <cstdio>
#include <cstdlib>
#include <cstring>
const int m=100000;
int s[100001],f[200001];
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      if (!x)
         x=-1;
      s[i]=s[i-1]+x;
   }
   memset(f,-1,sizeof(f));
   f[m]=0;
   int ans=0;
   for (int i=1;i<=n;i++)
      if (f[s[i]+m]==-1)
         f[s[i]+m]=i;
      else
      {
         int now=i-f[s[i]+m];
         if (now>ans)
            ans=now;
      }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
