#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
const double eps=1e-7;
int main()
{
   string s;
   while (cin>>s)
   {
      double p;
      if (s[0]=='-')
      {
         p=-1;
         s.erase(0,1);
      }
      else
         p=1;
      s+="0000";
      double x=(s[0]-'0')*100+(s[2]-'0')*10+s[3]-'0';
      if (s[4]>='5')
         x++;
      printf("%.2f\n",(p*x+eps)/100);
   }
   system("pause");
   return(0);
}
