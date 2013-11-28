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
#include <string>
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
char S[2000010];
int c[10];
string s;
int main()
{
   void work(),did();
   int T;
   scanf("%d",&T);
   c[0]=1;
   for (int i=1;i<=5;i++)
      c[i]=c[i-1]*26;
   while (T--)
   {
      scanf("%s",S);
      s=S;
      int p=s.find('C');
      if (p>0 && isdigit(s[p-1]) && p<=s.size()-1 && isdigit(s[p+1]))
         work();
      else
         did();
   }
   system("pause");
   return(0);
}
void work()
{
   void calc(int);
   int p=s.find('C');
   calc(atoi(s.substr(p+1).c_str()));
   printf("%s\n",s.substr(1,p-1).c_str());
}
void calc(int x)
{
   int t=1;
   while (c[t]<x)
      x-=c[t++];
   for (int i=t;i;i--)
   {
      for (int j=1;j<=26;j++)
         if (j*c[i-1]>=x)
         {
            x-=(j-1)*c[i-1];
            printf("%c",j+'A'-1);
            break;
         }
   }
}
void did()
{
   int p;
   for (int i=0;i<s.size();i++)
      if (isdigit(s[i]))
      {
         p=i;
         break;
      }
   printf("R%sC",s.substr(p).c_str());
   int x=0;
   for (int i=0;i<p;i++)
      x=x*26+s[i]-'A'+1;
   printf("%d\n",x);
}
