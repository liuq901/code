#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[1010];
int main()
{
   int n;
   while (scanf("%d",&n)==1)
   {
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      sort(a+1,a+n+1);
      for (int i=1;i<=n;i++)
         printf("%d%c",a[i],i==n?'\n':' ');
   }
   system("pause");
   return(0);
}
