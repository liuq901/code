#include <cstdio>
#include <cstdlib>
#include <string>
#include <utility>
#include <map>
using namespace std;
typedef map <string,int>::iterator type;
map <string,int> p;
char s[100];
int main()
{
   int n=0;
   bool flag=false;
   while (gets(s))
   {
      string a=s;
      if (a!="")
      {
         type k=p.find(a);
         if (k==p.end())
            p.insert(make_pair(a,1));
         else
            k->second++;
         n++;
      }
      else
      {
         if (flag)
            printf("\n");
         flag=true;
         for (type k=p.begin();k!=p.end();k++)
            printf("%s %.4lf\n",k->first.c_str(),100.0*k->second/n);
         n=0;
         p.clear();
      }
   }
   if (n)
   {
      if (flag)
         printf("\n");
      for (type k=p.begin();k!=p.end();k++)
         printf("%s %.4lf\n",k->first.c_str(),100.0*k->second/n);
   }
   system("pause");
   return(0);
}
