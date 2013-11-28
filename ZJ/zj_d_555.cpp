#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100010],ans[100010];
int main()
{
   int n;
   while (scanf("%d",&n)==1)
   {
      memset(a,-1,sizeof(a));
      for (int i=1;i<=n;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         a[x]=max(a[x],y);
      }
      int m=0,now=-1;
      for (int i=100000;i>=0;i--)
         if (a[i]>now)
         {
            now=a[i];
            ans[++m]=i;
         }
      static int id=0;
      printf("Case %d:\n",++id);
      printf("Dominate Point: %d\n",m);
      for (int i=m;i;i--)
         printf("(%d,%d)\n",ans[i],a[ans[i]]);
   }
   system("pause");
   return(0);
}
