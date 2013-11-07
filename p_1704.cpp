#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
   void work();
   int t;
   scanf("%d",&t);
   for (int i=1;i<=t;i++)
      work();
   system("pause");
   return(0);
}
void work()
{
   int n,a[10000];
   scanf("%d",&n);
   for (int i=0;i<n;i++)
      scanf("%d",&a[i]);
   if (n%2==1)
   {
      for (int i=n;i>=1;i--)
         a[i]=a[i-1];
      a[0]=0;
      n++;
   }
   sort(a,a+n);
   int s=0;
   for (int i=1;i<=n/2;i++)
      s^=a[2*i-1]-a[2*i-2]-1;
   if (s!=0)
      printf("Georgia will win\n");
   else
      printf("Bob will win\n");
}
