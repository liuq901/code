#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
int main()
{
   while (1)
   {
      string s,t;
      cin>>s;
      if (s=="#")
         break;
      cin>>t;
      int ans=0;
      while (s.find(t)!=string::npos)
      {
         ans++;
         s.erase(s.find(t),t.size());
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
