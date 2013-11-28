#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[1000010];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   sort(a+1,a+n+1);
   for (int i=1;i<m;i++)
      printf("%d ",a[i]);
   printf("%d\n",a[m]);
   system("pause");
   return(0);
}
