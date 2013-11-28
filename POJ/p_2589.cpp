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
#define MAXN 1100000
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const double eps=1e-7;
const double pi=acos(-1.0);
int a[2][MAXN],b[2][MAXN];
int main()
{
   void move(int *,int *),update(int *,int *);
   string print(int *);
   ios::sync_with_stdio(false);
   string s,t;
   cin>>s>>t;
   memset(a,0,sizeof(a));
   memset(b,0,sizeof(b));
   a[0][0]=s.size();
   for (int i=0;i<a[0][0];i++)
      a[0][a[0][0]-i]=s[i];
   b[0][0]=t.size();
   for (int i=0;i<b[0][0];i++)
      b[0][b[0][0]-i]=t[i];
   bool flag=false;
   for (int times=1;times<=1000;times++)
   {
      int x=a[0][a[0][0]--],y=b[0][b[0][0]--];
      a[1][++a[1][0]]=x,b[1][++b[1][0]]=y;
      if (x==y)
      {
         int p=rand()/99%2;
         if (!p)
            move(a[1],b[1]);
         else
            move(b[1],a[1]);
         cout<<"Snap! for "<<(p?"John":"Jane")<<": "<<print(p?b[1]:a[1])<<endl;
      }
      if (!a[0][0] && !a[1][0])
      {
         cout<<"John wins."<<endl;
         flag=true;
         break;
      }
      if (!b[0][0] && !b[1][0])
      {
         cout<<"Jane wins."<<endl;
         flag=true;
         break;
      }
      if (!a[0][0])
         update(a[0],a[1]);
      if (!b[0][0])
         update(b[0],b[1]);
   }
   if (!flag)
      cout<<"Keeps going and going ..."<<endl;
   return(0);
}
void move(int *a,int *b)
{
   for (int i=1;i<=b[0];i++)
      a[++a[0]]=b[i];
   b[0]=0;
}
void update(int *a,int *b)
{
   a[0]=b[0];
   for (int i=1;i<=a[0];i++)
      a[i]=b[a[0]-i+1];
   b[0]=0;
}
string print(int *a)
{
   string s;
   for (int i=a[0];i;i--)
      s+=a[i];
   return(s);
}

