#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
   int a,b,c,ans=0;
   while (scanf("%d%d%d",&a,&b,&c)==3)
   {
      if (a>c)
         swap(a,c);
      if (b>c)
         swap(b,c);
      ans+=a+b>c;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
