#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int m=100;
int f[110];
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      int a,b;
      scanf("%d%d",&a,&b);
      for (int j=m;j>=a;j--)
         f[j]=max(f[j],f[j-a]+b);
   }
   printf("%d\n",f[m]);
   system("pause");
   return(0);
}
