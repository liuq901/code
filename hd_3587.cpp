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
const int value[]={0,0,0,50,100,150,200,250,300,350,400};
struct state
{
   int time,kill;
   ll money;
   state(){}
   state(int _t,ll _m,int _k):time(_t),money(_m),kill(_k){}
};
map <string,state> a;
set <string> b,c;
string s,t;
int main()
{
   int n,m,q;
   while (scanf("%d%d%d",&n,&m,&q)!=EOF)
   {
      a.clear();
      b.clear();
      c.clear();
      while (n--)
      {
         cin>>s;
         a[s]=state(0,603,0);
         b.insert(s);
      }
      while (m--)
      {
         cin>>s;
         a[s]=state(0,603,0);
         c.insert(s);
      }
      bool first_blood=true;
      while (q--)
      {
         char ch;
         cin>>ch;
         if (ch=='Q')
         {
            cin>>s;
            int x;
            scanf("%d",&x);
            a[s].money+=x-a[s].time;
            a[s].time=x;
            cout<<a[s].money<<endl;
         }
         else
         {
            cin>>s>>t;
            int x;
            scanf("%d",&x);
            a[s].money+=x-a[s].time;
            a[s].time=x;
            a[t].money+=x-a[t].time;
            a[t].time=x;
            a[t].money=max(0LL,a[t].money-300);
            a[t].kill=0;
            if (b.count(s) && c.count(t) || b.count(t) && c.count(s))
            {
               int add=200;
                  if (first_blood)
               add+=200,first_blood=false;
               a[s].kill=min(10,a[s].kill+1);
               add+=value[a[s].kill];
               a[s].money+=add;
            }
         }
      }
   }
   system("pause");
   return(0);
}
