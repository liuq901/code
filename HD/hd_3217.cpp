#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int a[70000];
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      int m;
      scanf("%d",&m);
      memset(a,0,sizeof(a));
      int t=(1<<n)-1;
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         int now=x^t;
         for (int j=now;j;j=j-1&now)
            a[x^j]+=y;
         a[x]+=y;
      }
      int ans=0;
      for (int i=1;i<1<<n;i++)
         ans=max(ans,a[i]);
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
