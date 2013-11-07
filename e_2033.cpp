#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
   string s;
   while (getline(cin,s))
   {
      reverse(s.begin(),s.end());
      printf("%s\n",s.c_str());
   }
   system("pause");
   return(0);
}
