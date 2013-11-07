#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
using namespace std;
int main()
{
   char ch;
   string s;
   while (scanf("%c",&ch)!=EOF)
      if (isalpha(ch))
         s=ch+s;
      else
      {
         printf("%s%c",s.c_str(),ch);
         s="";
      }
   printf("%s",s.c_str());
   system("pause");
   return(0);
}
