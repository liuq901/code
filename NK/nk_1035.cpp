#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <string>
#include <map>
#include <utility>
using namespace std;
typedef map <string,int>::iterator data;
map <string,int> a;
char s[100];
int main()
{
   int n;
   scanf("%d%*c",&n);
   for (int i=1;i<=n;i++)
   {
      gets(s);
      int len=strlen(s);
      if (len!=25)
         continue;
      bool flag=true;
      for (int i=0;i<len;i++)
      {
         if (!isalpha(s[i]))
         {
            flag=false;
            break;
         }
         s[i]=tolower(s[i]);
      }
      if (flag)
         a[s]++;
   }
   string ans="no solution";
   int num=-1;
   for (data k=a.begin();k!=a.end();k++)
      if (k->second>num)
         num=k->second,ans=k->first;
      else if (k->second==num)
         ans="no solution";
   printf("%s",ans.c_str());
   system("pause");
   return(0);
}
