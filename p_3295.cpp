#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cstdarg>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <numeric>
#include <functional>
#include <bitset>
#include <complex>
#include <iterator>
#include <memory>
#define SQR(x) ((x)*(x))
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const int mod=1000000007;
const double eps=1e-7;
const double pi=acos(-1.0);
stack <char> p;
char a[260];
int main()
{
   char N(char),K(char,char),A(char,char),C(char,char),E(char,char);
   string s;
   while (1)
   {
      cin>>s;
      if (s=="0")
         break;
      int n=s.size();
      bool flag=true;
      for (a['p']='0';a['p']<='1';a['p']++)
         for (a['q']='0';a['q']<='1';a['q']++)
            for (a['r']='0';a['r']<='1';a['r']++)
               for (a['s']='0';a['s']<='1';a['s']++)
                  for (a['t']='0';a['t']<='1';a['t']++)
                  {
                     for (int i=0;i<n;i++)
                     {
                        if (isupper(s[i]))
                        {
                           p.push(s[i]);
                           continue;
                        }
                        char now=a[s[i]];
                        while (1)
                        {
                           if (p.empty() || isupper(p.top()) && p.top()!='N')
                           {
                              p.push(now);
                              break;
                           }
                           if (p.top()=='N')
                           {
                              p.pop();
                              now=(N(now));
                           }
                           else
                           {
                              char x,y;
                              x=p.top(),p.pop(),y=p.top(),p.pop();
                              if (y=='K')
                                 now=(K(x,now));
                              else if (y=='A')
                                 now=(A(x,now));
                              else if (y=='C')
                                 now=(C(x,now));
                              else
                                 now=(E(x,now));
                           }
                        }
                     }
                     if (p.top()=='0')
                        flag=false;
                     p.pop();
                  }
      printf("%s\n",flag?"tautology":"not");
   }
   system("pause");
   return(0);
}
char N(char x)
{
   return(x=='0'?'1':'0');
}
char K(char x,char y)
{
   x-='0',y-='0';
   return((x && y)+'0');
}
char A(char x,char y)
{
   x-='0',y-='0';
   return((x || y)+'0');
}
char C(char x,char y)
{
   if (x=='1' && y=='0')
      return('0');
   return('1');
}
char E(char x,char y)
{
   return((x==y)+'0');
}
