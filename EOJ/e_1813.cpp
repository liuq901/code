#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
string s,t,ans;
int main()
{
   void calc(int,int,int,int);
   while (cin>>s>>t)
   {
      ans="";
      calc(0,s.size()-1,0,t.size()-1);
      printf("%s\n",ans.c_str());
   }
   system("pause");
   return(0);
}
void calc(int l1,int r1,int l2,int r2)
{
   if (l1>r1)
      return;
   if (l1==r1)
   {
      ans+=s[l1];
      return;
   }
   int pos;
   for (int i=l2;i<=r2;i++)
      if (t[i]==s[l1])
      {
         pos=i;
         break;
      }
   int p=pos-l2;
   calc(l1+1,l1+p,l2,pos-1);
   calc(l1+p+1,r1,pos+1,r2);
   ans+=t[pos];
}
