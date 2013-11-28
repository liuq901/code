#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
   int calc(string &);
   string s;
   while (getline(cin,s))
   {
      stringstream sin(s);
      string op,t,ans;
      sin>>t;
      ans+=t;
      int now=calc(t);
      while (sin>>op>>t)
      {
         int p=calc(t);
         if (op=="or")
         {
            ans+="||";
            now|=p;
         }
         else
         {
            ans+="&&";
            now&=p;
         }
         ans+=t;
      }
      ans+=" = ";
      t="";
      for (int i=0;i<5;i++)
         ans+=(now>>i&1)+'0';
      printf("%s\n",ans.c_str());
   }
   system("pause");
   return(0);
}
int calc(string &s)
{
   int ret=0;
   for (int i=4;i>=0;i--)
      ret=(ret<<1)+s[i]-'0';
   return(ret);
}
