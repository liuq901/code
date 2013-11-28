#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>
using namespace std;
pair <int,int> a[1010];
int b[1010],f[1010];
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      int m=0;
      for (int i=1;i<=n;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         if (x+y>=n)
            continue;
         a[++m].first=n-y,a[m].second=x+1;
      }
      sort(a+1,a+m+1);
      int t=0;
      for (int i=1;i<=m;i++)
      {
         if (!t || a[i]!=a[t])
         {
            a[++t]=a[i];
            b[t]=1;
            continue;
         }
         b[t]++;
      }
      for (int i=1;i<=t;i++)
         b[i]=min(b[i],a[i].first-a[i].second+1);
      int now=1;
      for (int i=1;i<=n;i++)
      {
         f[i]=f[i-1];
         while (now<=t && a[now].first==i)
         {
            f[i]=max(f[i],f[a[now].second-1]+b[now]);
            now++;
         }
      }
      static int id=0;
      printf("Case %d: %d\n",++id,n-f[n]);
   }
   system("pause");
   return(0);
}
