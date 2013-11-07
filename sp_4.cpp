#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
#include <stack>
using namespace std;
int main()
{
   int t;
   scanf("%d",&t);
   for (int i=1;i<=t;i++)
   {
      char tmp[500];
      string s;
      scanf("%s",tmp);
      s=tmp;
      int l;
      l=s.size();
      string ans;
      stack <char> a;
      for (int i=0;i<l;i++)
      {
         if (isalpha(s[i]))
            ans+=s[i];
         if (s[i]=='(')
            a.push(s[i]);
         if (s[i]==')')
         {
            while (a.top()!='(')
            {
               ans+=a.top();
               a.pop();
            }
            a.pop();
         }
         if (s[i]=='+')
            a.push(s[i]);
         if (s[i]=='-')
         {
            while (a.top()=='+')
            {
               ans+=a.top();
               a.pop();
            }
            a.push(s[i]);
         }
         if (s[i]=='*')
         {
            while (a.top()=='+' || a.top()=='-')
            {
               ans+=a.top();
               a.pop();
            }
            a.push(s[i]);
         }
         if (s[i]=='/')
         {
            while (a.top()=='+' || a.top()=='-' || a.top()=='*')
            {
               ans+=a.top();
               a.pop();
            }
            a.push(s[i]);
         }
         if (s[i]=='^')
         {
            while (a.top()=='+' || a.top()=='-' || a.top()=='*' || a.top()=='/')
            {
               ans+=a.top();
               a.pop();
            }
            a.push(s[i]);
         }
      }
      while (!a.empty())
      {
         ans+=a.top();
         a.pop();
      }
      printf("%s\n",ans.c_str());
   }
   system("pause");
   return(0);
}
