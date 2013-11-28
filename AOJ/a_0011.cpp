#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[40];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      a[i]=i;
   while (m--)
   {
      int x,y;
      scanf("%d,%d",&x,&y);
      swap(a[x],a[y]);
   }
   for (int i=1;i<=n;i++)
      printf("%d\n",a[i]);
   system("pause");
   return(0);
}
