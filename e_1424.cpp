#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
char S[100000];
int main()
{
   while (1)
   {
      gets(S);
      string s=S;
      int p1=s.find('+'),p2=s.find('=');
      string a=s.substr(0,p1),b=s.substr(p1+1,p2-p1-1),c=s.substr(p2+1);
      reverse(a.begin(),a.end());
      reverse(b.begin(),b.end());
      reverse(c.begin(),c.end());
      int x=atoi(a.c_str()),y=atoi(b.c_str()),z=atoi(c.c_str());
      printf("%s\n",x+y==z?"True":"False");
      if (s=="0+0=0")
         break;
   }
   system("pause");
   return(0);
}
