#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
int main()
{
   string check(string);
   string n,m;
   while (cin>>n>>m)
      printf("%s\n",check(n)==check(m)?"It's xiao qiang":"It isn't xiao qiang");
   system("pause");
   return(0);
}
string check(string s)
{
   string ans="";
   int l=s.size(),k=0;
   bool flag=false;
   if (s[0]=='-')
   {
      ans="-";
      k=1;
   }
   int t=-1;
   for (int i=k;i<l;i++)
   {
      if (s[i]=='.')
      {
         t=i;
         break;
      }
      if (s[i]!='0')
         flag=true;
      if (flag)
         ans+=s[i];
   }
   if (ans=="" || ans=="-")
      ans="0";
   if (t!=-1)
   {
      k=l;
      for (int i=l-1;i>t;i--)
         if (s[i]!='0')
         {
            k=i;
            break;
         }
      if (k!=l)
      {
         ans+=".";
         for (int i=t+1;t<=k;t++)
            ans+=s[i];
      }
   }
   return(ans);
}
