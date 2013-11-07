#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;
stack <int> s;
int main()
{
   int x;
   while (scanf("%d",&x)==1)
   {
      if (!x)
      {
         printf("%d\n",s.top());
         s.pop();
         continue;
      }
      s.push(x);
   }
   system("pause");
   return(0);
}
