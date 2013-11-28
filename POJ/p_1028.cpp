#include <cstdio>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;
int main()
{
   string now="http://www.acm.org/";
   stack <string> a,b;
   while (1)
   {
      char tmp[260];
      scanf("%s",tmp);
      string s;
      s=tmp;
      if (s=="QUIT")
         break;
      if (s=="VISIT")
      {
         scanf("%s",tmp);
         s=tmp;
         printf("%s\n",s.c_str());
         a.push(now);
         now=s;
         while (!b.empty())
            b.pop();
      }
      else if (s=="BACK")
      {
         if (a.empty())
         {
            printf("Ignored\n");
            continue;
         }
         printf("%s\n",a.top().c_str());
         b.push(now);
         now=a.top();
         a.pop();
      }
      else
      {
         if (b.empty())
         {
            printf("Ignored\n");
            continue;
         }
         printf("%s\n",b.top().c_str());
         a.push(now);
         now=b.top();
         b.pop();
      }
   }
   system("pause");
   return(0);
}
