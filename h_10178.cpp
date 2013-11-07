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
      int a,b;
      scanf("%d%d",&a,&b);
      printf("%d\n",__gcd(a,b));
   }
   system("pause");
   return(0);
}
