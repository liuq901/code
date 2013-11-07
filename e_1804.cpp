#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
int main()
{
   string s;
   cin>>s;
   int T;
   scanf("%d",&T);
   while (T--)
   {
      string op;
      cin>>op;
      if (op=="strcat")
      {
         string t;
         cin>>t;
         s+=t;
         printf("%s\n",s.c_str());
      }
      else if (op=="strsub")
      {
         int x,y;
         scanf("%d%d",&x,&y);
         printf("%s\n",x+y>s.size()?"fail":s.substr(x,y).c_str());
      }
      else
      {
         string t;
         cin>>t;
         printf("%s\n",s==t?"yes":"no");
      }
   }
   system("pause");
   return(0);
}
