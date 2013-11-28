#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[110];
int main()
{
   bool comp(int,int);
   int n;
   while (scanf("%d",&n)==1)
   {
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      sort(a+1,a+n+1,comp);
      for (int i=1;i<=n;i++)
         printf("%d%c",a[i],i==n?'\n':' ');
   }
   system("pause");
   return(0);
}
bool comp(int x,int y)
{
   return(abs(x)<abs(y));
}
