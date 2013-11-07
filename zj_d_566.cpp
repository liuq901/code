#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <set>
using namespace std;
typedef set <string>::iterator data;
set <string> a,b;
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      string s,t;
      cin>>s>>t;
      if (t=="AC")
         a.insert(s),b.insert(s);
      else
      {
         data k=a.find(s);
         if (k!=a.end())
            a.erase(k);
      }
   }
   printf("%d%%\n",a.size()*100/b.size());
   system("pause");
   return(0);
}
