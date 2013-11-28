#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cstdarg>
#include <iostream>
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
#define MAXN 1010
#define MAXM 1010
using namespace std;
struct date
{
   int year,month,day;
   date(int p)
   {
      year=p/10000;
      month=p%10000/100;
      day=p%100;
   }
   void print(int x)
   {
      cout<<setfill('0')<<setw(4)<<year<<"-"<<setw(2)<<month<<"-"<<setw(2)<<day<<" ";
      if (!x)
         cout<<"No merit or demerit points."<<endl;
      else if (x>0)
         cout<<x<<" merit point(s)."<<endl;
      else
         cout<<-x<<" demerit point(s)."<<endl;
   }
};
bool operator <(date a,date b)
{
   date c=a;
   c.year+=2;
   if (b.year<c.year)
      return(false);
   if (b.year==c.year && b.month<c.month)
      return(false);
   if (b.year==c.year && b.month==c.month && b.day<c.day)
      return(false);
   return(true);
}
bool operator <=(date a,date b)
{
   date c=a;
   c.year++;
   if (b.year<c.year)
      return(false);
   if (b.year==c.year && b.month<c.month)
      return(false);
   if (b.year==c.year && b.month==c.month && b.day<c.day)
      return(false);
   return(true);
}
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const double eps=1e-7;
const double pi=acos(-1.0);
int main()
{
   int n;
   cin>>n;
   date now(n);
   int sum=0;
   now.print(sum);
   int x,y;
   while (cin>>x>>y)
   {
      date p(x);
      while (1)
      {
         bool flag=false;
         if (sum<0 && now<=p)
         {
            now.year++;
            if (sum>=-2)
               sum=0;
            else
               sum/=2;
            flag=true;
            now.print(sum);
         }
         else if (sum<5 && sum>=0 && now<p)
         {
            now.year+=2;
            sum++;
            flag=true;
            now.print(sum);
         }
         if (!flag)
            break;
      }
      now=p;
      if (sum<=0)
         sum-=y;
      else if (y>=2*sum)
         sum=2*sum-y;
      else
         sum-=(y+1)/2;
      now.print(sum);
   }
   while (sum<5)
   {
      now.year+=sum<0?1:2;   
      if (sum<-2)
         sum/=2;
      else if (sum<0)
         sum=0;
      else
         sum++;
      now.print(sum);
   }
   system("pause");
   return(0);
}
