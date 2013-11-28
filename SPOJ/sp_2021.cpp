#include <cstdio>
#include <cstdlib>
#include <string>
#include <set>
using namespace std;
set <string> a;
char s[100010];
int main()
{
   int n;
   while (scanf("%d",&n)!=EOF)
   {
      a.clear();
      for (int i=1;i<=n;i++)
      {
         scanf("%s",s);
         string p=s;
         if (a.count(p))
            a.erase(p);
         else
            a.insert(p);
      }
      printf("%s\n",!a.empty()?"first player":"second player");
   }
   system("pause");
   return(0);
}
