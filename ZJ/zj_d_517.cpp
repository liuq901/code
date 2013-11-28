#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;
map <string,int> a;
int main()
{
   int T;
   while (scanf("%d",&T)==1)
   {
      a.clear();
      int n=0;
      while (T--)
      {
         char s[10];
         scanf("%s",s);
         if (!a.count(s))
         {
            printf("New! %d\n",++n);
            a[s]=n;
         }
         else
            printf("Old! %d\n",a[s]);
      }
   }
   system("pause");
   return(0);
}
