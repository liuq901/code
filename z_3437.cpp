#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
   void print(ll,char);
   char ch;
   int base;
   string s;
   while (cin>>ch>>base>>s)
   {
      ll ans=0,q=1;
      int p=0;
      if (s[0]=='-')
         p=1,q=-1;
      for (int i=s.size()-1;i>=p;i--)
      {
         int x=isalpha(s[i])?tolower(s[i])-'a'+10:s[i]-'0';
         ans+=q*x;
         q*=base;
      }
      print(ans,ch);
   }
   system("pause");
   return(0);
}
void print(ll num,char ch)
{
   if (ch=='!')
   {
      printf("%d\n",num?0:1);
      return;
   }
   if (ch=='-')
   {
      string s="";
      ll x=num;
      while (num)
      {
         s+=abs(num%10)+'0';
         num/=10;
      }
      if (x>0)
         s+='-';
      else if (!x)
         s="0";
      reverse(s.begin(),s.end());
      printf("%s\n",s.c_str());
      return;
   }
   printf("%lld\n",~num);
}
