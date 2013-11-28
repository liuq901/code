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
      int n,s1,s2;
      scanf("%d",&n);
      s1=s2=0;
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         s1+=(x+30)/30*10;
         s2+=(x+60)/60*15;
      }
      int cost=min(s1,s2);
      static int id=0;
      printf("Case %d: ",++id);
      if (s1==cost)
         printf("Mile ");
      if (s2==cost)
         printf("Juice ");
      printf("%d\n",cost);
   }
   system("pause");
   return(0);
}
