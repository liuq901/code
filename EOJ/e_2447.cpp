#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int x1[110],x2[110],y1[110],y2[110];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
      int ans=n;
      for (int i=1;i<=n;i++)
      {
         for (int j=1;j<=n;j++)
         {
            if (i==j)
               continue;
            if (min(x1[i],x2[i])>=max(x1[j],x2[j]))
               continue;
            if (max(x1[i],x2[i])<=min(x1[j],x2[j]))
               continue;
            if (min(y1[i],y2[i])>=max(y1[j],y2[j]))
               continue;
            if (max(y1[i],y2[i])<=min(y1[j],y2[j]))
               continue;
            ans--;
            break;
         }
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
