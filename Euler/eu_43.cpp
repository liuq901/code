#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int c[]={0,2,3,5,7,11,13,17};
typedef long long ll;
int a[10]={1,0,2,3,4,5,6,7,8,9};
int main()
{
   bool check();
   ll ans=0;
   while (1)
   {
      if (check())
      {
         ll now=0;
         for (int i=0;i<10;i++)
            now=now*10+a[i];
         ans+=now;
      }
      if (!next_permutation(a,a+10))
         break;
   }
   printf("%lld\n",ans);
   system("pause");
   return(0);
}
bool check()
{
   for (int i=1;i<=7;i++)
   {
      int p=a[i]*100+a[i+1]*10+a[i+2];
      if (p%c[i])
         return(false);
   }
   return(true);
}
