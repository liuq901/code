#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;
char s[1000000];
string ans;
int main()
{
   while (1)
   {
      gets(s);
      int n=strlen(s);
      ans="";
      bool flag=false;
      for (int i=0;i<n;i++)
      {
         if (i+2<n && s[i]=='E' && s[i+1]=='O' && s[i+2]=='F')
         {
            flag=true;
            break;
         }
         if (s[i]==' ' || s[i]=='\n' || s[i]=='\r' || s[i]=='\t')
         {
            ans+=s[i];
            continue;
         }
         if (!islower(s[i]))
            continue;
         if (i+1<n && s[i]=='d' && s[i+1]=='d')
         {
            ans+='p';
            i++;
         }
         else if (i+3<n && s[i]=='p' && s[i+1]=='i' && s[i+2]=='n' && s[i+3]=='k')
         {
            ans+="floyd";
            i+=3;
         }
         else if (i+1<n && s[i]=='e' && s[i+1]=='i' && (!i || s[i-1]!='c'))
         {
            ans+="ie";
            i++;
         }
         else
            ans+=s[i];
      }
      printf("%s\n",ans.c_str());
      if (flag)
         break;
   }
   system("pause");
   return(0);
}
