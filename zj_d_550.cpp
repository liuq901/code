#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
basic_string <int> a[10010];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
   {
      a[i].resize(m);
      for (int j=0;j<m;j++)
         scanf("%d",&a[i][j]);
   }
   sort(a+1,a+n+1);
   for (int i=1;i<=n;i++)
      for (int j=0;j<m;j++)
         printf("%d%c",a[i][j],j==m-1?'\n':' ');
   system("pause");
   return(0);
}
