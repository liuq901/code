#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
   int ans=1;
   for (int i=1;i<=20;i++)
   {
      int p=__gcd(ans,i);
      ans=ans/p*i;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
