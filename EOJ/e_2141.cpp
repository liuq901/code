#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
bool up[100010],down[100010],open[100010];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int high=0;
      memset(down,0,sizeof(down));
      memset(open,0,sizeof(open));
      memset(up,0,sizeof(up));
      int n,opentime,runtime;
      scanf("%d%d%d",&n,&opentime,&runtime);
      for (int i=1;i<=n;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         high=max(high,max(x,y));
         if (x>y)
            open[x]=true,down[y]=true;
         else
            up[x]=true,up[y]=true;
      }
      ll ans=ll(runtime)*(high-1<<1);
      for (int i=1;i<=high;i++)
         if (up[i])
         {
            ans+=opentime;
            open[i]=false;
         }
      for (int i=high;i;i--)
         if (open[i] || down[i])
            ans+=opentime;
      printf("%I64d\n",ans);
   }
   system("pause");
   return(0);
}
