#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[100010];
int main()
{
   int n=0,x;
   while (scanf("%d",&x)==1)
      a[n++]=x;
   sort(a,a+n);
   reverse(a,a+n);
   for (int i=0;i<n;i++)
      printf("%d%c",a[i],i==n-1?'\n':' ');
   system("pause");
   return(0);
}
