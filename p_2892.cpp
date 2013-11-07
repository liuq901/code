#include <cstdio>
#include <cstdlib>
#include <stack>
#include <set>
using namespace std;
typedef set <int>::iterator type;
stack <int> s;
set <int> a;
int main()
{
   int n,m;
   scanf("%d%d%*c",&n,&m);
   a.insert(0);
   a.insert(n+1);
   for (int i=1;i<=m;i++)
   {
      char ch;
      scanf("%c",&ch);
      if (ch=='R')
      {
         type k=a.find(s.top());
         a.erase(k);
         s.pop();
      }
      else
      {
         int x;
         scanf("%d",&x);
         if (ch=='D')
         {
            s.push(x);
            a.insert(x);
         }
         else if (a.count(x))
            printf("0\n");
         else
         {
            type t,k;
            t=k=a.lower_bound(x);
            t--;
            printf("%d\n",*k-*t-1);
         }
      }
      scanf("%*c");
   }
   system("pause");
   return(0);
}
