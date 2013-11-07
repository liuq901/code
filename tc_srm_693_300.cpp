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
struct OneRegister
{
   string getProgram(int s,int t)
   {
      a.insert(s);
      int l,r;
      l=r=1,q[1]=s;
      while (l<=r)
      {
         int x=q[l];
         if (x==t)
            return(print(l));
         if (x<=46360)
         {
            int t=SQR(x);
            if (!a.count(t))
            {
               a.insert(t);
               q[++r]=t;
               pre[r]=l;
               op[r]='*';
            }
         }
         if (x<=1073741823)
         {
            int t=x<<1;
            if (!a.count(t))
            {
               a.insert(t);
               q[++r]=t;
               pre[r]=l;
               op[r]='+';
            }
         }
         if (!a.count(0))
         {
            a.insert(0);
            q[++r]=0;
            pre[r]=l;
            op[r]='-';
         }
         if (!a.count(1))
         {
            a.insert(1);
            q[++r]=1;
            pre[r]=l;
            op[r]='/';
         }
         l++;
         if (r>1000000)
            break;
      }
      return(":-(");
   }
private:
   set <int> a;
   static int q[1000010],pre[1000010];
   static char op[1000010];
   string print(int x)
   {
      string ans;
      while (x!=1)
      {
         ans=op[x]+ans;
         x=pre[x];
      }
      return(ans);
   }
};
int OneRegister::q[1000010],OneRegister::pre[1000010];
char OneRegister::op[1000010];
int main()
{
   int s,t;
   scanf("%d%d",&s,&t);
   OneRegister p;
   cout<<p.getProgram(s,t)<<endl;
   system("pause");
   return(0);
}
