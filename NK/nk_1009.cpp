#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
   string s,t;
   cin>>s>>t;
   reverse(s.begin(),s.end());
   reverse(t.begin(),t.end());
   int a=0,b=0;
   for (int i=0;i<s.size();i++)
      a=a*10+s[i]-'0';
   for (int i=0;i<t.size();i++)
      b=b*10+t[i]-'0';
   a+=b;
   s.clear();
   while (a)
   {
      s+=a%10+'0';
      a/=10;
   }
   while (s[0]=='0')
      s.erase(0,1);
   printf("%s\n",s.c_str());
   system("pause");
   return(0);
}
