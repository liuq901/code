#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[1000010];
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   sort(a+1,a+n+1);
   for (int i=1;i<n;i++)
      printf("%d ",a[i]);
   printf("%d\n",a[n]);
   system("pause");
   return(0);
}
