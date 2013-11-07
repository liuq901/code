#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
   char s[100];
   scanf("%s",s);
   string a(s);
   reverse(a.begin(),a.end());
   printf("%d %s\n",a.size(),a.c_str());
   system("pause");
   return(0);
}
