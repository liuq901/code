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
struct RectangleAvoidingColoring
{
   ll count(vector <string> borad)
   {
      a=borad;
      n=a.size(),m=a[0].size();
      if (min(n,m)==1)
         return(work());
      if (min(n,m)==2)
         return(did());
      if (max(n,m)>=7 && min(n,m)>=3)
         return(0);
      if (max(n,m)>=5 && min(m,n)>=5)
         return(0);
      if (max(n,m)==6 && min(n,m)>=5)
         return(0);
      ans=0;
      search(0,0);
      return(ans);
   }
private:
   int n,m,ans;
   vector <string> a;
   ll work()
   {
      ll ans=1;
      for (int i=0;i<n;i++)
         for (int j=0;j<m;j++)
            if (a[i][j]=='?')
               ans<<=1;
      return(ans);
   }
   ll did()
   {
      string up,down;
      if (n==2)
         up=a[0],down=a[1];
      else
         for (int i=0;i<n;i++)
            up+=a[i][0],down+=a[i][1];
      ll l0,l1,l2,l3;
      n=max(n,m);
      l0=1;
      l1=l2=l3=0;
      for (int i=0;i<n;i++)
      {
         ll p0,p1,p2,p3;
         if (up[i]=='?' && down[i]=='?')
            p0=l0*2,p1=l0+l1*2,p2=l0+l2*2,p3=l1+l2+l3*2;
         else if (up[i]=='W' && down[i]=='W')
            p0=0,p1=l0,p2=0,p3=l2;
         else if (up[i]=='B' && down[i]=='B')
            p0=0,p1=0,p2=l0,p3=l1;
         else if (up[i]!='?' && down[i]!='?')
            p0=l0,p1=l1,p2=l2,p3=l3;
         else if (up[i]=='B' || down[i]=='B')
            p0=l0,p1=l1,p2=l0+l2,p3=l1+l3;
         else
            p0=l0,p1=l0+l1,p2=l2,p3=l2+l3;
         l0=p0,l1=p1,l2=p2,l3=p3;
      }
      return(l0+l1+l2+l3);
   }
   void search(int x,int y)
   {
      if (y==m)
         x++,y=0;
      if (x==n)
      {
         ans++;
         return;
      }
      if (a[x][y]=='?')
      {
         a[x][y]='B';
         if (check(x,y))
            search(x,y+1);
         a[x][y]='W';
         if (check(x,y))
            search(x,y+1);
         a[x][y]='?';
      }
      else if (check(x,y))
         search(x,y+1);
   }
   bool check(int x,int y)
   {
      for (int i=0;i<x;i++)
         for (int j=0;j<y;j++)
            if (a[i][j]==a[i][y] && a[i][j]==a[x][j] && a[i][j]==a[x][y])
               return(false);
      return(true);
   }
};
int main()
{
   int n;
   vector <string> a;
   scanf("%d",&n);
   a.resize(n);
   for (int i=0;i<n;i++)
      cin>>a[i];
   RectangleAvoidingColoring p;
   cout<<p.count(a)<<endl;
   system("pause");
   return(0);
}
