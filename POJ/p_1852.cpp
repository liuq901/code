#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,l;
      scanf("%d%d",&l,&n);
      int mi=0,ma=0;
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         ma=max(ma,max(x,l-x));
         mi=max(mi,min(x,l-x));
      }
      printf("%d %d\n",mi,ma);
   }
   system("pause");
   return(0);
}
