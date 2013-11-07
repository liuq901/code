#include <cstdio>
#include <cstdlib>
#include <list>
using namespace std;
typedef list <int>::iterator data;
list <int> a;
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      a.push_back(x);
   }
   int m;
   scanf("%d",&m);
   while (m--)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      for (data k=a.begin();k!=a.end();k++)
         if (*k==x)
         {
            a.insert(++k,y);
            break;
         }
      for (data k=a.begin();k!=a.end();k++)
      {
         if (k!=a.begin())
            printf(" ");
         printf("%d",*k);
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
