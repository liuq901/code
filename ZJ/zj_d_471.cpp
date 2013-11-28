#include <cstdio>
#include <string>
using namespace std;
string s;
int n;
int main()
{
   void search(int);
   while (scanf("%d",&n)==1)
   {
      s.resize(n);
      search(0);
   }
   system("pause");
   return(0);
}
void search(int dep)
{
   if (dep==n)
   {
      printf("%s\n",s.c_str());
      return;
   }
   s[dep]='0';
   search(dep+1);
   s[dep]='1';
   search(dep+1);
}
