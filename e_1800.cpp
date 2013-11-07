#include <cstdio>
#include <cstdlib>
#include <deque>
using namespace std;
deque <int> a;
int main()
{
   int n;
   scanf("%d",&n);
   a.resize(n);
   for (int i=0;i<n;i++)
      scanf("%d",&a[i]);
   int m;
   scanf("%d",&m);
   while (m--)
   {
      int x;
      scanf("%d",&x);
      if (x>a.size())
         printf("-1\n");
      else
      {
         printf("%d\n",a[x-1]);
         a.erase(a.begin()+x-1);
      }
   }
   system("pause");
   return(0);
}
