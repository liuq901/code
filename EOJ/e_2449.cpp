#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <stack>
using namespace std;
char s[1010];
stack <char> a;
int main()
{
   bool check(char);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      scanf("%s",s);
      int l=strlen(s);
      bool flag=true;
      for (int i=0;i<l;i++)
      {
         if (isalpha(s[i]))
         {
            if (a.empty())
            {
               flag=false;
               break;
            }
            continue;
         }
         if (s[i]=='{' || s[i]=='(' || s[i]=='[')
            a.push(s[i]);
         else if (!check(s[i]))
         {
            flag=false;
            break;
         }
         else
            a.pop();
      }
      if (!a.empty())
         flag=false;
      while (!a.empty())
         a.pop();
      printf("%s\n",flag?"YES":"NO");
   }
   system("pause");
   return(0);
}
bool check(char ch)
{
   if (a.empty())
      return(false);
   char t=a.top();
   return(ch=='}' && t=='{' || ch==']' && t=='[' || ch==')' && t=='(');
}
