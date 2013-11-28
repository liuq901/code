#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
   int T,X,n,limit=1<<30;
   scanf("%d%d%d",&T,&X,&n);
   for (int i=1;i<=n;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      limit=min(limit,(x-1)/y);
   }
   int ans;
   if (!limit)
      ans=0;
   else
      ans=T<=limit?T:limit+(T-limit>>1);
   printf("%d\n",ans*X);
   system("pause");
   return(0);
}
