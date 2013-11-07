#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;
set <int> s;
int a[3010];
int main()
{
   for (int i=1;i<=3000;i++)
   {
      a[i]=i*(3*i-1)>>1;
      s.insert(a[i]);
   }
   for (int i=1;i<=3000;i++)
      for (int j=i;j<=3000;j++)
         if (s.count(a[i]+a[j]) && s.count(a[j]-a[i]))
            printf("%d\n",a[j]-a[i]);
   system("pause");
   return(0);
}
