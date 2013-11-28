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
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
typedef long long ll;
typedef long double ld;
const int inf=1061109567;
const double eps=1e-7;
const double pi=acos(-1.0);
struct IsingModel
{
   int energy(vector <string> a)
   {
      int n=a.size(),m=a[0].size(),ans=0;
      for (int i=0;i<n;i++)
         for (int j=0;j<m;j++)
            for (int k=0;k<4;k++)
            {
               int x=i+c[k][0],y=j+c[k][1];
               if (x>=0 && x<n && y>=0 && y<m)
                  ans+=a[x][y]==a[i][j]?-1:1;
            }
      return(ans>>1);
   }
};
int main()
{
   int n;
   scanf("%d",&n);
   vector <string> a;
   while (n--)
   {
      string s;
      cin>>s;
      a.push_back(s);
   }
   IsingModel p;
   printf("%d\n",p.energy(a));
   system("pause");
   return(0);
}
